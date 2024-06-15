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
/*   Updated: 2024/06/15 07:58:22 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ray_all_elements_present(t_gm *gm)
{
	if (!gm->map.n_img.ref || !gm->map.e_img.ref
		|| !gm->map.s_img.ref || !gm->map.w_img.ref
		|| gm->map.c_rgb.hex < 0 || gm->map.f_rgb.hex < 0)
			ray_fail_exit("Missing element");
}

int	ray_map_contents_only(char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
		return (0);
	while (str[++i] != '\0')
	{
		if ((str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] != 'E'
				&& str[i] != 'S' && str[i] != 'W' && str[i] != ' '
				&& str[i] != '\t' && (str[i] != '\n' || i == 0))
			|| str[ft_strlen(str) - 1] != '\n')
			return (-1);
	}
	return (1);
}

int	ray_is_all_num(char *str1, char *str2, char *str3)
{
	while (*str1 != '\0')
	{
		if (*str1 < '0' || *str1 > '9')
			return (0);
		str1++;
	}
	while (*str2 != '\0')
	{
		if (*str2 < '0' || *str2 > '9')
			return (0);
		str2++;
	}
	while (*str3 != '\0')
	{
		if (*str3 < '0' || *str3 > '9')
			return (0);
		str3++;
	}
	return (1);
}

void	ray_trim_back_spaces(char *str, int len)
{
	if (len == 0 || str[len] != ' ')
		return ;
	if (str[len] == ' ')
		str[len] = '\0';
	ray_trim_back_spaces(str, len - 1);
}

// int	ray_contains_only(char *str, char *to_find)
// {
// 	int	i;
// 	int	j;
// 	int	res;

// 	i = -1;
// 	while (str[++i] != '\0')
// 	{
// 		j = -1;
// 		res = 0;
// 		while (to_find[++j] != '\0')
// 		{
// 			if (str[i] == to_find[j])
// 				res = 1;
// 		}
// 		if (res == 0)
// 			return (0);
// 	}
// 	return (1);
// }