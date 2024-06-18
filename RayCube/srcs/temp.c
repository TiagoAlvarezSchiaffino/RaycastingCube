/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   temp.c                                   		                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/15 06:58:56 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/18 08:17:12 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	print_ll(t_list **list)
{
	t_list	*node;

	node = *list;
	ft_printf("\nNormal linked list:\n");
	while (node != NULL)
	{
		ft_printf("|%s|\n", *(char **)node->content);
		node = node->next;
	}
}

void	print_dl(t_list **list)
{
	t_list	*node;
	int		i;

	node = *list;
	i = 0;
	ft_printf("\nDoor linked list:\n");
	while (node != NULL)
	{
		ft_printf("i: %d| x: %d\t| y: %d\t|\n", i++, ((t_vct *)node->content)->x, ((t_vct *)node->content)->y);
		node = node->next;
	}
}

void	print_da(char **array)
{
	int	i;

	i = -1;
	ft_printf("\nDouble array:\n");
	while (array[++i] != 0)
		ft_printf("|%s|\n", array[i]);
}