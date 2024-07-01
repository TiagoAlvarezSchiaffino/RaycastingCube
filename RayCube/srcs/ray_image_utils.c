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
/*   Updated: 2024/07/01 08:38:22 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

/* End == 0 : BGRA */
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

void	ray_color_block(t_gm *gm, t_ivct cur, unsigned int color)
{
	t_dvct	px;

	px.y = -1;
	while (++px.y < MMAP_PX)
	{
		px.x = -1;
		while (++px.x < MMAP_PX)
		{
			change_color(gm, color,
				(((cur.y * MMAP_PX) + px.y) * gm->map.main->sl)
				+ (((cur.x * MMAP_PX) + px.x) * 4), gm->map.main->addr);
		}
	}
}

void	ray_copy_main(t_gm *gm, int src_pixel, int x, int y)
{
	gm->map.mini->addr[(y * gm->map.mini->sl) + (x * 4) + 0]
		= gm->map.main->addr[src_pixel + 0];
	gm->map.mini->addr[(y * gm->map.mini->sl) + (x * 4) + 1]
		= gm->map.main->addr[src_pixel + 1];
	gm->map.mini->addr[(y * gm->map.mini->sl) + (x * 4) + 2]
		= gm->map.main->addr[src_pixel + 2];
	gm->map.mini->addr[(y * gm->map.mini->sl) + (x * 4) + 3]
		= gm->map.main->addr[src_pixel + 3];
}

void	ray_color_image(t_gm *gm, t_img *img, int color)
{
	t_ivct	pos;

	pos.y = -1;
	while (++pos.y < MMAP_H * MMAP_PX)
	{
		pos.x = -1;
		while (++pos.x < MMAP_W * MMAP_PX)
			change_color(gm, color, (pos.y * img->sl) + (pos.x * 4), img->addr);
	}
}