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
/*   Updated: 2024/06/18 08:47:41 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

int	ray_user_input(int keycode, t_gm *gm)
{
	if (keycode == KEY_ESC)
		ray_success_exit();
	return (0);
	(void)gm;
}