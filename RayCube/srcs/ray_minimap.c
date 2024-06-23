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
/*   Updated: 2024/06/23 07:30:49 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	create_map(t_gm *gm)
{
	int	x;
	int	y;

	gm->map.main->ref = mlx_new_image(gm->mlx, gm->map.size.x * MMAP_PX,
			gm->map.size.y * MMAP_PX);
	gm->map.main->addr = mlx_get_data_addr(gm->map.main->ref, &gm->map.main->bpp, &gm->map.main->sl,
			&gm->map.main->end);
	y = -1;
	while (++y < gm->map.size.y)
	{
		x = -1;
		while (++x < gm->map.size.x)
		{
			if (gm->map.map[y][x] == '1')
				ray_draw_block(gm, x, y, WHITE);
			else if (gm->map.map[y][x] == 'D')
				ray_draw_block(gm, x, y, BROWN);
		}
	}
}

static void	create_minimap(t_gm *gm)
{
	return ;
	(void)gm;
}

void	ray_display_minimap(t_gm *gm)
{
	create_map(gm);
	create_minimap(gm);
	mlx_put_image_to_window(gm->mlx, gm->win.ref, gm->map.main->ref, 0, 0);
	return ;
}