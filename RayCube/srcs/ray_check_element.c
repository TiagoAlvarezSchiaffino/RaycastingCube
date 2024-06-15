/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_check_element.c                                   		              */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/15 05:54:12 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/15 07:37:44 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	set_texture(t_img *img, void *mlx, char **split)
{
	if (split[1] == NULL)
		ray_fail_exit("No path set for texture");
	if (img->ref != NULL)
		ray_fail_exit("Duplicated texture found");
	img->ref = mlx_xpm_file_to_image(mlx, split[1], &img->size.x, &img->size.y);
	if (img->ref == NULL)
		ray_fail_exit("Invalid path set for texture");
}

static void	set_color(t_rgb *rgb, char **split)
{
	char	**rgb_split;

	if (split[1] == NULL)
		ray_fail_exit("No color set for floor or ceiling");
	else if (ft_getwc_charset(split[1], ", \t\n") != 3 || split[2] != NULL)
		ray_fail_exit("Invalid RGB valuesss");
	rgb_split = ft_split_charset(split[1], ", \t\n");
	rgb->r = ft_atoi(rgb_split[0]);
	rgb->g = ft_atoi(rgb_split[1]);
	rgb->b = ft_atoi(rgb_split[2]);
	if (rgb->r > 255 || rgb->g > 255 || rgb->b > 255
		|| !ray_is_all_num(rgb_split[0], rgb_split[1], rgb_split[2]))
		ray_fail_exit("Invalid RGB values");
	rgb->hex = (0 << 24 | rgb->r << 16 | rgb->g << 8 | rgb->b);
	ft_freesplit(rgb_split);
}

static void	get_element(t_gm *gm, char **split)
{
	if (ft_strcmp(split[0], "NO") == 0)
		set_texture(&gm->map.n_img, gm->mlx, split);
	else if (ft_strcmp(split[0], "EA") == 0)
		set_texture(&gm->map.e_img, gm->mlx, split);
	else if (ft_strcmp(split[0], "SO") == 0)
		set_texture(&gm->map.s_img, gm->mlx, split);
	else if (ft_strcmp(split[0], "WE") == 0)
		set_texture(&gm->map.w_img, gm->mlx, split);
	else if (ft_strcmp(split[0], "F") == 0)
		set_color(&gm->map.f_rgb, split);
	else if (ft_strcmp(split[0], "C") == 0)
		set_color(&gm->map.c_rgb, split);
}

void	ray_check_element(t_gm *gm, char **av)
{
	int		fd;
	char	*str;
	char	**split;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ray_fail_exit("Cannot open file");
	str = get_next_line(fd);
	while (str)
	{
		split = ft_split_charset(str, " \t\n");
		get_element(gm, split);
		ray_get_map(gm, str, fd);
		ft_freesplit(split);
		str = get_next_line(fd);
	}
	close(fd);
	if (gm->map.map != NULL)
		print_da(gm->map.map);
}