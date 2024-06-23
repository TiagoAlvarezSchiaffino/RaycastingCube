/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_minimap.c                                   		                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/23 07:12:50 by Tiago                     /   (_____/    */
/*   Updated: 2024/06/23 07:16:55 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	change_color(t_gm *gm, int color, int pixel, char *addr)
{
	if (gm->mini->end == 1)
	{
		addr[pixel + 0] = (color >> 24);
		addr[pixel + 1] = (color >> 16) & 0xFF;
		addr[pixel + 2] = (color >> 8) & 0xFF;
		addr[pixel + 3] = (color) & 0xFF;
	}
	else if (gm->mini->end == 0)
	{
		addr[pixel + 0] = (color) & 0xFF;
		addr[pixel + 1] = (color >> 8) & 0xFF;
		addr[pixel + 2] = (color >> 16) & 0xFF;
		addr[pixel + 3] = (color >> 24);
	}
}

/* (y * line size) + (x * 4) */
static void	draw_block(t_gm *gm, int x, int y, int color)
{
	int	px;
	int	py;

	py = -1;
	while (++py < MMAP_PX)
	{
		px = -1;
		while (++px < MMAP_PX)
		{
			change_color(gm, color, (((y * MMAP_PX) + py) * gm->mini->sl)
				+ (((x * MMAP_PX) + px) * 4), gm->mini->addr);
		}
	}
}

static void	create_map(t_gm *gm)
{
	int	x;
	int	y;

	y = -1;
	while (++y < gm->map.size.y)
	{
		x = -1;
		while (++x < gm->map.size.x)
		{
			if (gm->map.map[y][x] == '1')
				draw_block(gm, x, y, WHITE);
			if (gm->map.map[y][x] == 'D')
				draw_block(gm, x, y, BROWN);
		}
	}
}

void	ray_display_minimap(t_gm *gm)
{
	if (gm->mini == NULL)
		gm->mini = ft_calloc(1, sizeof(t_mini));
	gm->mini->ref = mlx_new_image(gm->mlx, gm->map.size.x * MMAP_PX,
			gm->map.size.y * MMAP_PX);
	gm->mini->addr = mlx_get_data_addr(gm->mini->ref, &gm->mini->bpp, &gm->mini->sl,
			&gm->mini->end);
	create_map(gm);
	mlx_put_image_to_window(gm->mlx, gm->win.ref, gm->mini->ref, 10, 10);
	return ;
	(void)gm;
}