/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_render_utils.c                                   		              */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/07/01 09:31:33 by Tiago                    /   (_____/     */
/*   Updated: 2024/07/01 09:38:05 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	set_variables(t_gm *gm, int x)
{
	gm->render.camera_x = 2 * x / (double)WIN_W - 1;
	gm->render.raydir_x = gm->ply.dir.x + gm->ply.plane.x
		* gm->render.camera_x;
	gm->render.raydir_y = gm->ply.dir.y + gm->ply.plane.y
		* gm->render.camera_x;
	gm->render.offset_x = gm->ply.pos.x + 0.5;
	gm->render.offset_y = gm->ply.pos.y + 0.5;
	gm->render.map_x = (int)gm->render.offset_x;
	gm->render.map_y = (int)gm->render.offset_y;
	if (gm->render.raydir_x == 0)
		gm->render.delta_dist_x = 1e30;
	else
		gm->render.delta_dist_x = fabs(1 / gm->render.raydir_x);
	if (gm->render.raydir_y == 0)
		gm->render.delta_dist_y = 1e30;
	else
		gm->render.delta_dist_y = fabs(1 / gm->render.raydir_y);
	gm->render.hit = 0;
}

void	check_steps(t_gm *gm)
{
	if (gm->render.raydir_x < 0)
	{
		gm->render.step_x = -1;
		gm->render.side_dist_x = (gm->render.offset_x - gm->render.map_x)
			* gm->render.delta_dist_x;
	}
	else
	{
		gm->render.step_x = 1;
		gm->render.side_dist_x = (gm->render.map_x + 1.0 - gm->render.offset_x)
			* gm->render.delta_dist_x;
	}
	if (gm->render.raydir_y < 0)
	{
		gm->render.step_y = -1;
		gm->render.side_dist_y = (gm->render.offset_y - gm->render.map_y)
			* gm->render.delta_dist_y;
	}
	else
	{
		gm->render.step_y = 1;
		gm->render.side_dist_y = (gm->render.map_y + 1.0 - gm->render.offset_y)
			* gm->render.delta_dist_y;
	}
}

void	set_length(t_gm *gm)
{
	gm->render.line_height = (int)(WIN_H / gm->render.perp_wall_dist);
	gm->render.draw_start = -gm->render.line_height / 2 + WIN_H / 2;
	gm->render.draw_end = gm->render.line_height / 2 + WIN_H / 2;
	if (gm->render.side == 0)
		gm->render.wall_x = gm->render.offset_y
			+ gm->render.perp_wall_dist * gm->render.raydir_y;
	else
		gm->render.wall_x = gm->render.offset_x
			+ gm->render.perp_wall_dist * gm->render.raydir_x;
	gm->render.wall_x -= floor((gm->render.wall_x));
}

void	check_sides(t_gm *gm, t_img *curimg)
{
	gm->render.tex_x = (int)(gm->render.wall_x * (double)(curimg->size.x));
	if (gm->render.side == 0)
	{
		if (gm->render.raydir_x > 0)
			gm->render.tex_x = curimg->size.x
				- (curimg->size.x - gm->render.tex_x - 1);
		else
			gm->render.tex_x = curimg->size.x
				- gm->render.tex_x - 1;
	}
	if (gm->render.side == 1)
	{
		if (gm->render.raydir_y < 0)
			gm->render.tex_x = curimg->size.x
				- (curimg->size.x - gm->render.tex_x - 1);
		else
			gm->render.tex_x = curimg->size.x
				- gm->render.tex_x - 1;
	}
}