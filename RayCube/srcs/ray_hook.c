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
/*   Updated: 2024/06/23 07:10:23 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ray_hooks(t_gm *gm)

{
	mlx_hook(gm->win.ref, EXIT_EVENT, EXIT_MASK, &ray_success_exit, NULL);
	mlx_key_hook(gm->win.ref, &ray_user_input, gm);
	mlx_loop_hook(gm->mlx, &ray_display, gm);
	mlx_loop(gm->mlx);
}