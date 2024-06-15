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
/*   Updated: 2024/06/15 06:58:35 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

int	main(int ac, char **av)
{
	t_gm	gm;

	ray_init_gm(&gm);
	ray_check_file(&gm, ac, av);
	ray_hooks(&gm);
	// mlx_loop(gm.mlx);
	ray_success_exit();
	return (0);
	(void)gm;
}