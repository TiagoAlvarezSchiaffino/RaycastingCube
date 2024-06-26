/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_player_control.c                                   		          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/26 07:25:06 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/26 08:09:51 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ray_player_movement(t_gm *gm, int keycode)
{
	if (keycode == KEY_W)
		gm->ply.pos.y -= PLY_MVSPD;
	else if (keycode == KEY_A)
		gm->ply.pos.x -= PLY_MVSPD;
	else if (keycode == KEY_S)
		gm->ply.pos.y += PLY_MVSPD;
	else if (keycode == KEY_D)
		gm->ply.pos.x += PLY_MVSPD;
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		printf("POS X: %f Y: %f\n", gm->ply.pos.x, gm->ply.pos.y);
}

void	ray_player_view(t_gm *gm, int keycode)
{
	double	dir_x;
	double	plane_x;
	double	rot_spd;

	rot_spd = PLY_ROTSPD;
	if (keycode == KEY_LEFT)
		rot_spd = -PLY_ROTSPD;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		dir_x = gm->ply.dir.x;
		gm->ply.dir.x = gm->ply.dir.x * cos(rot_spd)
			- gm->ply.dir.y * sin(rot_spd);
		gm->ply.dir.y = gm->ply.dir.y * cos(rot_spd)
			+ dir_x * sin(rot_spd);
		plane_x = gm->ply.plane.x;
		gm->ply.plane.x = gm->ply.plane.x * cos(rot_spd)
			- gm->ply.plane.y * sin(rot_spd);
		gm->ply.plane.y = gm->ply.plane.y * cos(rot_spd)
			+ plane_x * sin(rot_spd);
	}
}