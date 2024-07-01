/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_display.c                                   		                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/23 07:02:22 by Tiago                    /   (_____/     */
/*   Updated: 2024/07/01 09:50:08 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	clearimgwindow(t_gm *gm)
{
	int	i;
	int	k;

	i = 0;
	while (i < WIN_W)
	{
		k = 0;
		while (k < WIN_H)
		{
			if (k < WIN_H / 2)
				ray_my_mlx_pixel_put(&gm->map.imgw, i, k, gm->map.c_rgb.hex);
			else
				ray_my_mlx_pixel_put(&gm->map.imgw, i, k, gm->map.f_rgb.hex);
			k++;
		}
		i++;
	}
}

int	ray_display(t_gm *gm)
{
	clearimgwindow(gm);
	mlx_clear_window(gm->mlx, gm->win.ref);
	if (gm->win.mouse == 0)
		ray_mouse_control(gm);
	ray_render(gm);
	ray_renderdoor(gm);
	ray_display_minimap(gm);
	ray_update_door(gm);
	return (0);
}