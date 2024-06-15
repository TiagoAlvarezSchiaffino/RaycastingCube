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
/*   Updated: 2024/06/15 06:59:49 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	print_ll(t_list **list)
{
	t_list	*node;

	node = *list;
	while (node != NULL)
	{
		ft_printf("|%s|\n", *(char **)node->content);
		node = node->next;
	}
}