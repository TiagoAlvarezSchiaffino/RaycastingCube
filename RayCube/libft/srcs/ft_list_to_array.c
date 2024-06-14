/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_list_to_array.c  		                                   		      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 09:08:57 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 09:10:06 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_list_to_array(t_list *lst, int elem_size)
{
	void	*buffer;
	void	*head;

	if (lst == NULL)
		return (NULL);
	buffer = ft_calloc(ft_lstsize(lst), elem_size);
	head = buffer;
	while (lst != NULL)
	{
		ft_memcpy(buffer, lst->content, elem_size);
		lst = lst->next;
		buffer += elem_size;
	}
	return (head);
}