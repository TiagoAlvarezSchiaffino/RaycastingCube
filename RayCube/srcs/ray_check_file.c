/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_check_file.c                                   		              */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/15 06:03:19 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/28 06:20:44 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

char	**ray_dup_map(char **map, int height)
{
	int		y;
	char	**output;

	output = ft_calloc(height + 1, sizeof(char *));
	y = -1;
	while (++y < height)
		output[y] = ft_strdup(map[y]);
	return (output);
}

static void	check_file_format(int ac, char **av)
{
	int		errno;

	if (ac < 2)
		ray_fail_exit("./cub3D [map.cub]", NULL);
	errno = 0;
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4) != 0)
		ray_fail_exit("Invalid file format", av[1]);
}

void	ray_check_file(t_gm *gm, int ac, char **av)
{
	check_file_format(ac, av);
	ray_check_element(gm, av);
	if (gm->map.map != NULL)
		ray_check_map(gm, 0, 0);
	if (gm->ply.e_dir == NOTSET)
		ray_fail_exit("No player set in map", NULL);
	gm->map.map_raw = ray_dup_map(gm->map.map, gm->map.size.y);
	ray_orient_map(gm);
}