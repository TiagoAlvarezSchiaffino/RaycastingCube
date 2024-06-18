/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_main.c                                   		                      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 08:32:18 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/18 08:15:00 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

int	main(int ac, char **av)
{
	t_gm	gm;

	ray_init_gm(&gm);
	ray_check_file(&gm, ac, av);
	ray_hooks(&gm);
	mlx_put_image_to_window(gm.mlx, gm.win.ref, gm.map.n_img.ref, 0, 0);
	mlx_put_image_to_window(gm.mlx, gm.win.ref, gm.map.e_img.ref, 100, 0);
	mlx_put_image_to_window(gm.mlx, gm.win.ref, gm.map.s_img.ref, 200, 0);
	mlx_put_image_to_window(gm.mlx, gm.win.ref, gm.map.w_img.ref, 300, 0);
	mlx_put_image_to_window(gm.mlx, gm.win.ref, gm.map.d_img.ref, 400, 0);
	print_da(gm.map.map);
	mlx_loop(gm.mlx);
	ray_success_exit();
	return (0);
	(void)gm;
}