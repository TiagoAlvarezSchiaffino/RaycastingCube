/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_renderdoor.c                                   		              */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/07/01 10:05:12 by Tiago                    /   (_____/     */
/*   Updated: 2024/07/01 10:21:27 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	check_hit(t_gm *gm)
{
	while (gm->render.hit == 0)
	{
		if (gm->render.side_dist.x < gm->render.side_dist.y)
		{
			gm->render.side_dist.x += gm->render.delta_dist.x;
			gm->render.map.x += gm->render.step.x;
			gm->render.side = 0;
		}
		else
		{
			gm->render.side_dist.y += gm->render.delta_dist.y;
			gm->render.map.y += gm->render.step.y;
			gm->render.side = 1;
		}
		if ((gm->map.map[(int)gm->render.map.y][(int)gm->render.map.x] == 'D')
			|| gm->map.map[(int)gm->render.map.y][(int)gm->render.map.x] == '1')
			gm->render.hit = 1;
	}
}

void	ray_renderdoor(t_gm *gm)
{
	t_img	*curimg;
	int		x;

	x = -1;
	while (++x < WIN_W)
	{
		ray_set_variables(gm, x);
		ray_check_steps(gm);
		check_hit(gm);
		if (gm->render.side == 0)
			gm->render.perp_wall_dist = (gm->render.side_dist.x
					- gm->render.delta_dist.x);
		else
			gm->render.perp_wall_dist = (gm->render.side_dist.y
					- gm->render.delta_dist.y);
		curimg = &gm->map.d_img;
		ray_set_length(gm);
		ray_check_sides(gm, curimg);
		if (gm->map.map[(int)gm->render.map.y][(int)gm->render.map.x] == 'D')
			ray_draw_verline(curimg, x, gm);
	}
	mlx_put_image_to_window(gm->mlx, gm->win.ref, gm->map.imgw.ref, 0, 0);
}