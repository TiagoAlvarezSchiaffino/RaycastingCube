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
/*   Updated: 2024/06/23 07:09:10 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	draw_verline(t_gm *gm, int i, int draw_start, int draw_end, int color)
{
	while (draw_start < draw_end)
	{
		// mlx_put_image_to_window(gm->mlx, gm->win.ref, gm->map.n_img.ref,
			// i, draw_start);
		mlx_pixel_put(gm->mlx, gm->win.ref, i, draw_start, color);
		draw_start++;
	}
}

void	ray_render(t_gm *gm)
{
	int	x;

	x = -1;
	while (++x <= WIN_W)
	{
		double camera_x = 2 * x / (double)WIN_W - 1;
		double ray_dir_x = gm->ply.dir.x + gm->ply.plane.x * camera_x;
		double ray_dir_y = gm->ply.dir.y + gm->ply.plane.y * camera_x;

		int map_x = (int)gm->ply.pos.x;
		int map_y = (int)gm->ply.pos.y;

		double side_dist_x;
		double side_dist_y;

		double delta_dist_x = fabs(1 / ray_dir_x);
		double delta_dist_y = fabs(1 / ray_dir_y);
		if (ray_dir_x == 0)
			delta_dist_x = 1e30;
		if (ray_dir_y == 0)
			delta_dist_y = 1230;

		double perp_wall_dist;

		int	step_x;
		int	step_y;

		int	hit = 0;
		int	side;

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (gm->ply.pos.x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - gm->ply.pos.x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
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

		int color = BLUE;
		if (side == 1)
			color = color / 2;
		draw_verline(gm, x, draw_start, draw_end, color);
	}
}

int	ray_display(t_gm *gm)
{
	// ray_render(gm);
	ray_display_minimap(gm);
	return (0);
}