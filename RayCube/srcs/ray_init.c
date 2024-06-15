/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_init.c                                   		                      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/15 06:08:46 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/15 06:10:07 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ray_init_gm(t_gm *gm)
{
	gm->mlx = mlx_init();
	gm->win.ref = mlx_new_window(gm->mlx, WIN_H, WIN_W, "cub3D");
	gm->map.n_img.ref = NULL;
	gm->map.e_img.ref = NULL;
	gm->map.s_img.ref = NULL;
	gm->map.w_img.ref = NULL;
	gm->map.c_rgb.hex = -1;
	gm->map.f_rgb.hex = -1;
}