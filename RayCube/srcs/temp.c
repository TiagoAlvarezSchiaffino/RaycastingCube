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
/*   Updated: 2024/06/26 07:48:59 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	print_ll(t_list **list)
{
	t_list	*node;

	node = *list;
	printf("\nNormal linked list:\n");
	while (node != NULL)
	{
		printf("|%s|\n", *(char **)node->content);
		node = node->next;
	}
}

void	print_dl(t_list **list)
{
	t_list	*node;
	int		i;

	node = *list;
	i = 0;
	printf("\nDoor linked list:\n");
	while (node != NULL)
	{
		printf("i: %d| x: %d\t| y: %d\t|\n", i++,
			((t_ivct *)node->content)->x, ((t_ivct *)node->content)->y);
		node = node->next;
	}
}

void	print_da(char **array)
{
	int	i;

	i = -1;
	printf("\nDouble array:\n");
	while (array[++i] != 0)
		printf("|%s|\n", array[i]);
}