/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_render.c                                   		                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/07/01 09:24:06 by Tiago                    /   (_____/     */
/*   Updated: 2024/07/01 09:31:20 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	check_hit(t_gm *gm)
{
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
		gm->render.perp_wall_dist = (gm->render.side_dist_x
				- gm->render.delta_dist_x);
	else
		gm->render.perp_wall_dist = (gm->render.side_dist_y
				- gm->render.delta_dist_y);
}

static t_img	*set_image(t_gm *gm)
{
	t_img	*curimg;

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
	return (curimg);
}

void	ray_render(t_gm *gm)
{
	t_img	*curimg;
	int		x;

	x = -1;
	while (++x < WIN_W)
	{
		set_variables(gm, x);
		check_steps(gm);
		check_hit(gm);
		curimg = set_image(gm);
		set_length(gm);
		check_sides(gm, curimg);
		draw_verline(curimg, x, gm);
	}
	mlx_put_image_to_window(gm->mlx, gm->win.ref, gm->map.imgw.ref, 0, 0);
}