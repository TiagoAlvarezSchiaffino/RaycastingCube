/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_check_map.c                                   		                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/15 06:49:51 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/18 08:43:24 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static int	check_square(t_gm *gm, int x, int y)
{
	if (y < 0 || y >= gm->map.size.y || x < 0 || x >= gm->map.size.x)
		return (1);
	return (gm->map.map[y][x] != '1' && gm->map.map[y][x] != '0'
		&& gm->map.map[y][x] != 'N' && gm->map.map[y][x] != 'E'
		&& gm->map.map[y][x] != 'S' && gm->map.map[y][x] != 'W'
		&& gm->map.map[y][x] != 'D');
}	

static void	set_dir(t_gm *gm, int dir, int x, int y)
{
	gm->ply.e_dir = dir;
	gm->ply.dir.x = (double)x;
	gm->ply.dir.y = (double)y;
}

static void	get_ply_dir(t_gm *gm, int x, int y)
{
	if (gm->map.map[y][x] == 'N' || gm->map.map[y][x] == 'E'
		|| gm->map.map[y][x] == 'S' || gm->map.map[y][x] == 'W')
	{
		if (gm->ply.e_dir != NOTSET)
			ray_fail_exit("Duplicated player position in map", NULL);
		if (gm->map.map[y][x] == 'N')
			set_dir(gm, NORTH, 1, 0);
		else if (gm->map.map[y][x] == 'E')
			set_dir(gm, EAST, 0, 1);
		else if (gm->map.map[y][x] == 'S')
			set_dir(gm, SOUTH, 0, -1);
		else if (gm->map.map[y][x] == 'W')
			set_dir(gm, WEST, -1, 0);
		gm->ply.pos.x = (double)x;
		gm->ply.pos.y = (double)y;
	}
}

static void	get_door(t_gm *gm, int x, int y)
{
	t_ivct	vct;
	t_list	*new;

	if (gm->map.map[y][x] != 'D')
		return ;
	vct.x = x;
	vct.y = y;
	new = ft_lstnew(ft_calloc(1, sizeof(t_ivct)));
	ft_memcpy(new->content, &vct, sizeof(t_ivct));
	ft_lstadd_back(&gm->map.door, new);
}

void	ray_check_map(t_gm *gm, int x, int y)
{
	int	error;

	error = 0;
	if (y < 0 || y >= gm->map.size.y || x < 0 || x >= gm->map.size.x)
		return ;
	if (gm->map.map[y][x] == '0' || gm->map.map[y][x] == 'N'
		|| gm->map.map[y][x] == 'E' || gm->map.map[y][x] == 'S'
		|| gm->map.map[y][x] == 'W' || gm->map.map[y][x] == 'D')
	{
		get_ply_dir(gm, x, y);
		get_door(gm, x, y);
		error += check_square(gm, x + 1, y);
		error += check_square(gm, x - 1, y);
		error += check_square(gm, x, y + 1);
		error += check_square(gm, x, y - 1);
		if (error)
			ray_fail_exit("Map not surrounded by walls", NULL);
	}
	ray_check_map(gm, x + 1, y);
	if (x == 0)
		ray_check_map(gm, x, y + 1);
}