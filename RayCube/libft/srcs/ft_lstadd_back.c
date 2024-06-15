/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_lstadd_back.c                                   		              */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 09:01:12 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/15 06:15:16 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (!lst || !*lst || !new)
		return ;
	if (*lst != NULL)
	{
		list = ft_lstlast(*lst);
		list->next = new;
	}
	else
		*lst = new;
}