/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_array_to_list.c                          		                      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 08:30:04 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 08:31:21 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* To use: ft_printf("%type\n", *(type *)content); */
t_list	*ft_array_to_list(void *array, int array_size, int elem_size)
{
	t_list	*head;
	void	*content;
	int		i;

	head = NULL;
	i = -1;
	while (++i < array_size)
	{
		content = ft_calloc(1, elem_size);
		ft_memcpy(content, array, elem_size);
		ft_lstadd_back(&head, ft_lstnew(content));
		array += elem_size;
	}
	return (head);
}