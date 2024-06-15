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
/*   Updated: 2024/06/15 06:57:38 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	add_map(t_list **map_list, char *str)
{
	t_list	*node;
	char	*temp;
	int		i;

	node = ft_lstnew(ft_calloc(1, sizeof(char *)));
	i = -1;
	temp = ft_calloc(1, sizeof(char *));
	while (str[++i] != '\0')
	{
		if (str[i] == '\t')
			temp = ft_strjoin_free(temp, "    ");
		else if (str[i] != '\n')
			temp = ft_append_char(temp, str[i]);
	}
	ft_memcpy(node->content, &temp, sizeof(char *));
	ft_lstadd_back(map_list, node);
}

static void	map_is_valid(t_list **map_list)
{
	static int	checked = 0;

	if (checked)
		return ;
	checked = 1;
	print_ll(map_list);
}

void	ray_check_map(t_gm *gm, char *str, int fd)
{
	static int		mapmode = 0;
	static t_list	*map_list = NULL;

	if (ray_map_contents_only(str) == 0)
	{
		free(str);
		if (mapmode && str != NULL)
			ray_fail_exit("Extra new line at end of file");
		return ;
	}
	ray_all_elements_present(gm);
	mapmode = 1;
	add_map(&map_list, str);
	free(str);
	ray_check_map(gm, get_next_line(fd), fd);
	map_is_valid(&map_list);
}