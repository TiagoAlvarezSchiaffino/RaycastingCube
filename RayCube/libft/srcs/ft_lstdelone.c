/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_lstdelone.c		                                   		              */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 09:03:00 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 09:03:44 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	(*del)(lst->content);
	temp = lst->next;
	free(lst);
	lst = temp;
}