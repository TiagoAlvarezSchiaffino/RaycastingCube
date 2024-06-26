/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_hook.c                                   		                      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/15 06:07:50 by Tiago                    /   (_____/     */
/*   Updated: 2024/07/01 08:36:41 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static int	ray_user_input(int keycode, t_gm *gm)
{
	if (keycode == KEY_ESC)
		ray_success_exit();
	ray_player_vertical_movement(gm, keycode);
	ray_player_horizontal_movement(gm, keycode);
	ray_player_view(gm, keycode);
	ray_mouse_state(gm, keycode);
	ray_door_state(gm, keycode);
	return (0);
}

void	ray_hooks(t_gm *gm)
{
	mlx_hook(gm->win.ref, EXIT_EVENT, EXIT_MASK, &ray_success_exit, NULL);
	mlx_hook(gm->win.ref, KD_EVENT, KEY_PRESS, &ray_user_input, gm);
	mlx_loop_hook(gm->mlx, &ray_display, gm);
	mlx_loop(gm->mlx);
}