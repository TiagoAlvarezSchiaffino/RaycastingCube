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
/*   Updated: 2024/06/26 08:07:25 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

int	ray_fail_exit(char *msg, char *details)
{
	ft_dprintf(2, "Error\n");
	ft_dprintf(2, "%s", msg);
	if (details != NULL)
		ft_dprintf(2, ": |%s|", details);
	ft_dprintf(2, "\n");
	system("leaks -q cub3D");
	exit(1);
	return (1);
}

int	ray_success_exit(void)
{
	printf("Thanks for playing!\n");
	system("leaks -q cub3D");
	exit(0);
	return (0);
}