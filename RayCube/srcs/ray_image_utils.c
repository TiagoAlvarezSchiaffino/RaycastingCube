/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_image_utils.c                                   		              */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/23 07:22:28 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/23 07:38:12 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	change_color(t_gm *gm, unsigned int color, int pixel, char *addr)
{
	if (gm->map.main->end == 1)
	{
		addr[pixel + 0] = (color >> 24) & 0xFF;
		addr[pixel + 1] = (color >> 16) & 0xFF;
		addr[pixel + 2] = (color >> 8) & 0xFF;
		addr[pixel + 3] = (color) & 0xFF;
	}
	else if (gm->map.main->end == 0)
	{
		addr[pixel + 0] = (color) & 0xFF;
		addr[pixel + 1] = (color >> 8) & 0xFF;
		addr[pixel + 2] = (color >> 16) & 0xFF;
		addr[pixel + 3] = (color >> 24) & 0xFF;
	}
}

void	ray_draw_block(t_gm *gm, int x, int y, unsigned int color)
{
	int	px;
	int	py;

	py = -1;
	while (++py < MMAP_PX)
	{
		px = -1;
		while (++px < MMAP_PX)
		{
			change_color(gm, color, (((y * MMAP_PX) + py) * gm->map.main->sl)
				+ (((x * MMAP_PX) + px) * 4), gm->map.main->addr);
		}
	}
}

// void	ray_copy_image(t_img *dst, t_img *src, int x, int y)
// {

// }