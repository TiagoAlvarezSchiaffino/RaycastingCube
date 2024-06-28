/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_display.c                                   		                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/23 07:02:22 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/28 05:33:10 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->sl + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

static void	draw_verline(t_img *img, int i, int draw_start, int draw_end, int colorofx, t_gm *gm)
{
	char	*dest;
	double		y;
	int		newcolor;
	double	factor;

	y = 0;
		factor = ((double)(img->size.y - 1) / (double)(draw_end - draw_start));
	while (draw_start < draw_end)
	{
		dest = img->addr + ((int)y * img->sl + colorofx * (img->bpp / 8));
		newcolor = *(unsigned int *)dest;
		my_mlx_pixel_put(&gm->map.imgw, i, draw_start, newcolor);
		draw_start++;
		y = y + factor;
	}
}

void	ray_render(t_gm *gm)
{
	t_img	*curimg;
	int	x;

	x = -1;
	while (++x < WIN_W)
	{
		double cameraX = 2 * x / (double)WIN_W - 1;
		double rayDirX = gm->ply.dir.x + gm->ply.plane.x * cameraX;
		double rayDirY = gm->ply.dir.y + gm->ply.plane.y * cameraX;

		int map_x = (int)gm->ply.pos.x;
		int map_y = (int)gm->ply.pos.y;

		double side_dist_x;
		double side_dist_y;

		double delta_dist_x = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double delta_dist_y = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		double perp_wall_dist;

		int	step_x;
		int	step_y;

		int	hit = 0;
		int	side;

		if (rayDirX < 0)
		{
			step_x = -1;
			side_dist_x = (gm->ply.pos.x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - gm->ply.pos.x) * delta_dist_x;
		}
		if (rayDirY < 0)
		{
			step_y = -1;
			side_dist_y = (gm->ply.pos.y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - gm->ply.pos.y) * delta_dist_y;
		}

		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}

			if (gm->map.map[(int)map_y][(int)map_x] == '1')
				hit = 1;
		}

		if (side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
		else
			perp_wall_dist = (side_dist_y - delta_dist_y);

		int	line_height = (int)(WIN_H / perp_wall_dist);

		int	draw_start = -line_height / 2 + WIN_H / 2;
		if (draw_start < 0)
			draw_start = 0;
		int	draw_end = line_height / 2 + WIN_H / 2;
		if (draw_end >= WIN_H)
			draw_end = WIN_H - 1;

		// CODE HERE IS FOR PIXEL TEXTURE
		if (side == 0)
		{
			if (step_x == 1)
				curimg = &gm->map.n_img;
			else
				curimg = &gm->map.s_img;
		}
		else
		{
			if (step_y == 1)
				curimg = &gm->map.w_img;
			else
				curimg = &gm->map.e_img;
		}
		//calculate value of wallX
		double wallX; //where exactly the wall was hit
		if (side == 0) wallX = gm->ply.pos.y + perp_wall_dist * rayDirY;
		else           wallX = gm->ply.pos.x + perp_wall_dist * rayDirX;
		wallX -= floor((wallX));

		//x coordinate on the texture
		int texX = (int)(wallX * (double)(curimg->size.x));
		if(side == 0)
		{
			if (rayDirX > 0)
				texX = curimg->size.x - (curimg->size.x - texX - 1);
			else
				texX = curimg->size.x - texX - 1;
		}
		if(side == 1) 
		{
			if (rayDirY < 0)
				texX = curimg->size.x - (curimg->size.x - texX - 1);
			else
				texX = curimg->size.x - texX - 1;
		}
		draw_verline(curimg, x, draw_start, draw_end, texX, gm);
	}
	mlx_put_image_to_window(gm->mlx, gm->win.ref, gm->map.imgw.ref, 0, 0);
}

int	ray_display(t_gm *gm)
{
	int	i;
	int	k;

	i = 0;
	//Sets img window to black so can turn around
	while (i < WIN_W)
	{
		k = 0;
		while (k < WIN_H)
		{
			my_mlx_pixel_put(&gm->map.imgw, i, k, TBLACK);
			k++;
		}
		i++;
	}
	mlx_clear_window(gm->mlx, gm->win.ref);
	if (gm->win.mouse == 0)
		ray_mouse_control(gm);
	ray_render(gm);
	// ray_display_minimap(gm); USES A LOT OF MEMORY AND KEEPS INCERASING
	return (0);
}