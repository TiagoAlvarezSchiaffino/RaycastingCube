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
/*   Updated: 2024/06/23 07:49:33 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	player_movement(t_gm *gm, int keycode)
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

int	ray_user_input(int keycode, t_gm *gm)
{
	mlx_clear_window(gm->mlx, gm->win.ref);
	if (keycode == KEY_ESC)
		ray_success_exit();
	player_movement(gm, keycode);
	ray_display_minimap(gm);
	return (0);
}