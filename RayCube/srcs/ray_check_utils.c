/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_check_utils.c                                   		              */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/15 06:31:04 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/15 06:33:13 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ray_all_elements_present(t_gm *gm, int fd)
{
	close(fd);
	if (!gm->map.n_img.ref || !gm->map.e_img.ref
		|| !gm->map.s_img.ref || !gm->map.w_img.ref
		|| gm->map.c_rgb.hex < 0 || gm->map.f_rgb.hex < 0)
		ray_fail_exit("Missing element");
}

int	ray_map_contents_only(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] != 'E'
			&& str[i] != 'S' && str[i] != 'W' && str[i] != ' ' && str[i] != '\t'
			&& (str[i] != '\n' || i == 0))
			return (0);
	}
	return (1);
}