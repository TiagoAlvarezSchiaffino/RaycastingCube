/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_lstmap.c		                                   		              */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 09:04:49 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 09:06:27 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*head;

	if (!lst)
		return (NULL);
	newlist = ft_lstnew((*f)(lst->content));
	if (newlist == NULL)
		return (NULL);
	(void)(*del);
	lst = lst->next;
	head = newlist;
	while (lst != NULL)
	{
		newlist->next = ft_lstnew((*f)(lst->content));
		newlist = newlist->next;
		if (newlist == NULL)
			return (NULL);
		lst = lst->next;
	}
	return (head);
}