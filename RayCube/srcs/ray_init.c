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
/*   Updated: 2024/06/23 07:27:03 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ray_init_gm(t_gm *gm)
{
	gm->mlx = mlx_init();
	gm->win.ref = mlx_new_window(gm->mlx, WIN_W, WIN_H, "cub3D");
	gm->win.frame = 0;
	gm->map.n_img.ref = NULL;
	gm->map.e_img.ref = NULL;
	gm->map.s_img.ref = NULL;
	gm->map.w_img.ref = NULL;
	gm->map.d_img.ref = NULL;
	gm->map.door = NULL;
	gm->map.map = NULL;
	gm->map.c_rgb.hex = -1;
	gm->map.f_rgb.hex = -1;
	gm->ply.e_dir = NOTSET;
	gm->ply.plane.x = 0;
	gm->ply.plane.y = 0.66;
	gm->map.main = ft_calloc(1, sizeof(t_img));
	gm->map.mini = ft_calloc(1, sizeof(t_img));

}