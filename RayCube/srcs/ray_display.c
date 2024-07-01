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
/*   Updated: 2024/07/01 08:10:34 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->sl + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	draw_verline(t_img *img, int i, int draw_start, int draw_end, int colorofx, t_gm *gm)
{
	char	*dest;
	double	y;
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
		gm->render.camera_x = 2 * x / (double)WIN_W - 1;
		gm->render.raydir_x = gm->ply.dir.x + gm->ply.plane.x * gm->render.camera_x;
		gm->render.raydir_y = gm->ply.dir.y + gm->ply.plane.y * gm->render.camera_x;

		gm->render.map_x = (int)gm->ply.pos.x;
		gm->render.map_y = (int)gm->ply.pos.y;

		gm->render.delta_dist_x = (gm->render.raydir_x == 0) ? 1e30 : fabs(1 / gm->render.raydir_x);
		gm->render.delta_dist_y = (gm->render.raydir_y == 0) ? 1e30 : fabs(1 / gm->render.raydir_y);

		gm->render.hit = 0;

		if (gm->render.raydir_x < 0)
		{
			gm->render.step_x = -1;
			gm->render.side_dist_x = (gm->ply.pos.x - gm->render.map_x) * gm->render.delta_dist_x;
		}
		else
		{
			gm->render.step_x = 1;
			gm->render.side_dist_x = (gm->render.map_x + 1.0 - gm->ply.pos.x) * gm->render.delta_dist_x;
		}
		if (gm->render.raydir_y < 0)
		{
			gm->render.step_y = -1;
			gm->render.side_dist_y = (gm->ply.pos.y - gm->render.map_y) * gm->render.delta_dist_y;
		}
		else
		{
			gm->render.step_y = 1;
			gm->render.side_dist_y = (gm->render.map_y + 1.0 - gm->ply.pos.y) * gm->render.delta_dist_y;
		}

		while (gm->render.hit == 0)
		{
			if (gm->render.side_dist_x < gm->render.side_dist_y)
			{
				gm->render.side_dist_x += gm->render.delta_dist_x;
				gm->render.map_x += gm->render.step_x;
				gm->render.side = 0;
			}
			else
			{
				gm->render.side_dist_y += gm->render.delta_dist_y;
				gm->render.map_y += gm->render.step_y;
				gm->render.side = 1;
			}

			if (gm->map.map[(int)gm->render.map_y][(int)gm->render.map_x] == '1')
				gm->render.hit = 1;
		}

		if (gm->render.side == 0)
			gm->render.perp_wall_dist = (gm->render.side_dist_x - gm->render.delta_dist_x);
		else
			gm->render.perp_wall_dist = (gm->render.side_dist_y - gm->render.delta_dist_y);

		int	line_height = (int)(WIN_H / gm->render.perp_wall_dist);

		int	draw_start = -line_height / 2 + WIN_H / 2;
		if (draw_start < 0)
			draw_start = 0;
		int	draw_end = line_height / 2 + WIN_H / 2;
		if (draw_end >= WIN_H)
			draw_end = WIN_H - 1;

		// CODE HERE IS FOR PIXEL TEXTURE
		if (gm->render.side == 0)
		{
			if (gm->render.step_x == 1)
				curimg = &gm->map.e_img;
			else
				curimg = &gm->map.w_img;
		}
		else
		{
			if (gm->render.step_y == 1)
				curimg = &gm->map.s_img;
			else
				curimg = &gm->map.n_img;
		}
		//calculate value of wallX
		double wallX; //where exactly the wall was hit
		if (gm->render.side == 0) wallX = gm->ply.pos.y + gm->render.perp_wall_dist * gm->render.raydir_y;
		else           wallX = gm->ply.pos.x + gm->render.perp_wall_dist * gm->render.raydir_x;
		wallX -= floor((wallX));

		//x coordinate on the texture
		int texX = (int)(wallX * (double)(curimg->size.x));
		if(gm->render.side == 0)
		{
			if (gm->render.raydir_x > 0)
				texX = curimg->size.x - (curimg->size.x - texX - 1);
			else
				texX = curimg->size.x - texX - 1;
		}
		if(gm->render.side == 1) 
		{
			if (gm->render.raydir_y < 0)
				texX = curimg->size.x - (curimg->size.x - texX - 1);
			else
				texX = curimg->size.x - texX - 1;
		}
		draw_verline(curimg, x, draw_start, draw_end, texX, gm);
	}
	mlx_put_image_to_window(gm->mlx, gm->win.ref, gm->map.imgw.ref, 0, 0);
}

void	clearimgwindow(t_gm *gm)
{
	int	i;
	int	k;

	i = 0;
	//Sets img window half ceiling, half floor
	while (i < WIN_W)
	{
		k = 0;
		while (k < WIN_H)
		{
			if (k < WIN_H / 2)
				my_mlx_pixel_put(&gm->map.imgw, i, k, gm->map.c_rgb.hex);
			else
				my_mlx_pixel_put(&gm->map.imgw, i, k, gm->map.f_rgb.hex);
			k++;
		}
		i++;
	}
}

int	ray_display(t_gm *gm)
{
	clearimgwindow(gm);
	mlx_clear_window(gm->mlx, gm->win.ref);
	if (gm->win.mouse == 0)
		ray_mouse_control(gm);
	print_da(gm->map.map);
	ray_render(gm);
	printf("Ply plane x: %f\n", gm->ply.plane.x);
	printf("Ply plane y: %f\n", gm->ply.plane.y);
	ray_display_minimap(gm);
	return (0);
}