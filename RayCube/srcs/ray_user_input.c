/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_user_input.c                                   		              */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/18 08:47:12 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/23 08:03:01 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	player_movement(t_gm *gm, int keycode)
{
	if (keycode == KEY_W)
		gm->ply.pos.y -= PLY_MVSPD;
	else if (keycode == KEY_A)
		gm->ply.pos.x -= PLY_MVSPD;
	else if (keycode == KEY_S)
		gm->ply.pos.y += PLY_MVSPD;
	else if (keycode == KEY_D)
		gm->ply.pos.x += PLY_MVSPD;
	else if (keycode == KEY_LEFT)
	{
		double	old_dir_x = gm->ply.dir.x;
		gm->ply.dir.x = gm->ply.dir.x * cos(PLY_ROTSPD) - gm->ply.dir.y * sin(PLY_ROTSPD);
		gm->ply.dir.y = old_dir_x * sin(PLY_ROTSPD) + gm->ply.dir.y * cos(PLY_ROTSPD);
		double	old_plane_x = gm->ply.plane.x;
		gm->ply.plane.x = gm->ply.plane.x * cos(PLY_ROTSPD) - gm->ply.plane.y * sin(PLY_ROTSPD);
		gm->ply.plane.y = old_plane_x * sin(PLY_ROTSPD) + gm->ply.plane.y * cos(PLY_ROTSPD);
	}
	else if (keycode == KEY_RIGHT)
	{
		double	old_dir_x = gm->ply.dir.x;
		gm->ply.dir.x = gm->ply.dir.x * cos(-PLY_ROTSPD) - gm->ply.dir.y * sin(-PLY_ROTSPD);
		gm->ply.dir.y = old_dir_x * sin(-PLY_ROTSPD) + gm->ply.dir.y * cos(-PLY_ROTSPD);
		double	old_plane_x = gm->ply.plane.x;
		gm->ply.plane.x = gm->ply.plane.x * cos(-PLY_ROTSPD) - gm->ply.plane.y * sin(-PLY_ROTSPD);
		gm->ply.plane.y = old_plane_x * sin(-PLY_ROTSPD) + gm->ply.plane.y * cos(-PLY_ROTSPD);
	}
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		printf("POS X: %f Y: %f\n", gm->ply.pos.x, gm->ply.pos.y);
}

static void	system_command(t_gm *gm, int keycode)
{
	return ;
	(void)gm;
	(void)keycode;
}

int	ray_user_input(int keycode, t_gm *gm)
{
	if (keycode == KEY_ESC)
		ray_success_exit();
	// mlx_clear_window(gm->mlx, gm->win.ref);
	player_movement(gm, keycode);
	system_command(gm, keycode);
	ray_display_minimap(gm);
	return (0);
}