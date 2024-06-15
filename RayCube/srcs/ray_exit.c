/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_exit.c                                   		                      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/15 06:06:53 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/15 08:18:15 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

int	ray_fail_exit(char *str)
{
	ft_dprintf(2, "Error\n%s\n", str);
	system("leaks -q cub3D");
	exit(1);
	return (1);
}

int	ray_success_exit(void)
{
	ft_printf("Thanks for playing!\n");
	system("leaks -q cub3D");
	exit(0);
	return (0);
}