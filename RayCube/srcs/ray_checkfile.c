/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_checkfile.c                                   		                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/15 06:03:19 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/15 06:33:25 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

/**
 * - Map must be closed/surrounded by walls, else return an error.
 * - Except for map content, each type of element can be separated by one or more
 * empty lines
 * - Except for the map content which always has to be the last, each type of
 * element can be set in any order in the file.
 * - Except for the map, each type of information from an element can be
 * separated by one or more space(s)
 * 
 * NO ./path_to_the_north_texture
 * SO ./path_to_the_south_texture
 * WE ./path_to_the_south_texture
 * EA ./path_to_the_south_texture
 * 
 * F 0,123,255
 * C 0,123,255
 */

static void	check_file_format(int ac, char **av)
{
	int		errno;

	if (ac < 2)
		ray_fail_exit("./cub3D [map.cub]");
	errno = 0;
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4) != 0)
		ray_fail_exit("Invalid file format");
}

void	ray_check_file(t_gm *gm, int ac, char **av)
{
	check_file_format(ac, av);
	ray_check_element(gm, av);
}