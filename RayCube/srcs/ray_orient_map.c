/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_orient_map.c                                   		                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/26 07:49:06 by Tiago                     /   (_____/    */
/*   Updated: 2024/06/26 08:22:37 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	dup_map(t_gm *gm)
{
	t_ivct	cur;

	if (gm->map.map_in != NULL)
		ft_freesplit(gm->map.map_in);
	gm->map.map_in = ft_calloc(gm->map.size.y + 1, sizeof(char *));
	cur.y = -1;
	while (++cur.y < gm->map.size.y)
		gm->map.map_in[cur.y] = ft_strdup(gm->map.map[cur.y]);
	gm->map.map_in[cur.y] = 0;
}

static void	replace_map(t_gm *gm, t_ivct old, t_ivct new)
{
	while (++old.x < gm->map.size.x)
	{
		new.x = 0;
		old.y = gm->map.size.y;
		gm->map.map[new.y] = ft_calloc(gm->map.size.y + 1, sizeof(char));
		while (--old.y >= 0)
		{
			gm->map.map[new.y][new.x] = gm->map.map_in[old.y][old.x];
			if (gm->map.map[new.y][new.x] == 'N'
				|| gm->map.map[new.y][new.x] == 'E'
				|| gm->map.map[new.y][new.x] == 'S'
				|| gm->map.map[new.y][new.x] == 'W')
			{
				gm->ply.pos.x = new.x;
				gm->ply.pos.y = new.y;
			}
			new.x++;
		}
		new.y++;
	}
	gm->map.map[new.y] = 0;
}

static void	rotate_right(t_gm *gm)
{
	t_ivct	new;
	t_ivct	old;

	dup_map(gm);
	ft_freesplit(gm->map.map);
	gm->map.map = ft_calloc(gm->map.size.x + 1, sizeof(char *));
	new.y = 0;
	old.x = -1;
	replace_map(gm, old, new);
	ft_swap(&gm->map.size.x, &gm->map.size.y);
}

void	ray_orient_map(t_gm *gm)
{
	if (gm->ply.e_dir == WEST)
		rotate_right(gm);
	else if (gm->ply.e_dir == SOUTH)
	{
		rotate_right(gm);
		rotate_right(gm);
	}
	else if (gm->ply.e_dir == EAST)
	{
		rotate_right(gm);
		rotate_right(gm);
		rotate_right(gm);
	}
	print_da(gm->map.map);
}