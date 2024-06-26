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
/*   Updated: 2024/06/26 07:48:11 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	create_map(t_gm *gm)
{
	t_ivct	cur;

	gm->map.main->ref = mlx_new_image(gm->mlx, gm->map.size.x * MMAP_PX,
			gm->map.size.y * MMAP_PX);
	gm->map.main->addr = mlx_get_data_addr(gm->map.main->ref,
			&gm->map.main->bpp, &gm->map.main->sl, &gm->map.main->end);
	cur.y = -1;
	while (++cur.y < gm->map.size.y)
	{
		cur.x = -1;
		while (++cur.x < gm->map.size.x)
		{
			if (gm->map.map[cur.y][cur.x] == '1')
				ray_color_block(gm, cur, TWHITE);
			else if (gm->map.map[cur.y][cur.x] == ' ')
				ray_color_block(gm, cur, TBLACK);
			else if (gm->map.map[cur.y][cur.x] == 'D')
				ray_color_block(gm, cur, TBROWN);
			else
				ray_color_block(gm, cur, TGREY);
		}
	}
}

static void	copy_pixel(t_gm *gm, int src_pixel, int x, int y)
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

static void	create_minimap(t_gm *gm)
{
	t_ivct	cur;
	t_ivct	max;
	t_ivct	min;

	gm->map.mini->ref = mlx_new_image(gm->mlx,
			MMAP_W * MMAP_PX, MMAP_W * MMAP_PX);
	gm->map.mini->addr = mlx_get_data_addr(gm->map.mini->ref,
			&gm->map.mini->bpp, &gm->map.mini->sl, &gm->map.mini->end);
	min.y = (gm->ply.pos.y * MMAP_PX) - (MMAP_PX * (MMAP_H / 2)) - 1;
	max.y = (gm->ply.pos.y * MMAP_PX) + (MMAP_PX * ((MMAP_H / 2) + 1));
	min.x = (gm->ply.pos.x * MMAP_PX) - (MMAP_PX * (MMAP_W / 2)) - 1;
	max.x = (gm->ply.pos.x * MMAP_PX) + (MMAP_PX * ((MMAP_W / 2) + 1));
	cur.y = min.y;
	while (++cur.y < max.y)
	{
		cur.x = min.x;
		while (++cur.x < max.x)
		{
			if (cur.x >= 0 && cur.y >= 0
				&& cur.x <= (gm->map.size.x * MMAP_PX) - 1
				&& cur.y <= (gm->map.size.y * MMAP_PX) - 1)
				copy_pixel(gm, (cur.y * gm->map.main->sl) + (cur.x * 4),
					cur.x - min.x - 1, cur.y - min.y - 1);
		}
	}
}

static void	draw_player(t_gm *gm)
{
	t_ivct	pos;

	pos.x = MMAP_W * MMAP_PX / 2;
	pos.y = MMAP_H * MMAP_PX / 2;
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x - 1, pos.y - 1, GREEN);
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x, pos.y - 1, GREEN);
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x + 1, pos.y - 1, GREEN);
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x - 1, pos.y, GREEN);
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x, pos.y, GREEN);
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x + 1, pos.y, GREEN);
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x - 1, pos.y + 1, GREEN);
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x, pos.y + 1, GREEN);
	mlx_pixel_put(gm->mlx, gm->win.ref, pos.x + 1, pos.y + 1, GREEN);
}

void	ray_display_minimap(t_gm *gm)
{
	create_map(gm);
	create_minimap(gm);
	mlx_clear_window(gm->mlx, gm->win.ref);
	mlx_put_image_to_window(gm->mlx, gm->win.ref, gm->map.mini->ref, 0, 0);
	draw_player(gm);
}