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
/*   Updated: 2024/06/18 08:46:59 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ray_hooks(t_gm *gm)

{
	mlx_hook(gm->win.ref, EXIT_EVENT, EXIT_MASK, &ray_success_exit, NULL);
	mlx_key_hook(gm->win.ref, &c3d_user_input, gm);
}