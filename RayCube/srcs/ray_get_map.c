/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ray_get_map.c                                   		                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/15 07:58:40 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/15 08:05:53 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	add_map(t_list **map_list, char *str)
{
	t_list	*node;
	char	*temp;
	int		i;

	i = -1;
	node = ft_lstnew(ft_calloc(1, sizeof(char *)));
	temp = ft_calloc(1, sizeof(char *));
	while (str[++i] != '\0')
	{
		if (str[i] == '\t')
			temp = ft_strjoin_free(temp, "    ");
		else if (str[i] != '\n')
			temp = ft_append_char(temp, str[i]);
	}
	ray_trim_back_spaces(temp, ft_strlen(temp) - 1);
	ft_memcpy(node->content, &temp, sizeof(char *));
	ft_lstadd_back(map_list, node);
}

static int	get_map_width(t_list **map_list)
{
	t_list	*node;
	size_t	max;

	node = *map_list;
	max = 0;
	while (node != NULL)
	{
		if (max < ft_strlen(*(char **)node->content))
			max = ft_strlen(*(char **)node->content);
		node = node->next;
	}
	return (max);
}

static void	store_map(t_gm *gm, t_list **map_list)
{
	static int	checked = 0;
	t_list		*node;
	int			i;

	if (checked)
		return ;
	checked = 1;
	gm->map.y = ft_lstsize(*map_list);
	gm->map.x = get_map_width(map_list);
	gm->map.map = ft_calloc(gm->map.y + 1, sizeof(char *));
	i = -1;
	node = *map_list;
	while (++i < gm->map.y)
	{
		gm->map.map[i] = *(char **)node->content;
		node = node->next;
	}
	gm->map.map[i] = 0;
}

void	ray_get_map(t_gm *gm, char *str, int fd)
{
	static int		mapmode = 0;
	static t_list	*map_list = NULL;
	int				errno;

	errno = ray_map_contents_only(str);
	if (errno <= 0)
	{
		free(str);
		if (mapmode && errno == -1)
			ray_fail_exit("Invalid character in map");
		if (mapmode && str != NULL)
			ray_fail_exit("Extra new line at end of file");
		return ;
	}
	ray_all_elements_present(gm);
	mapmode = 1;
	add_map(&map_list, str);
	free(str);
	ray_get_map(gm, get_next_line(fd), fd);
	store_map(gm, &map_list);
}