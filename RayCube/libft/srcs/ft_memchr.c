/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_memchr.c          		                                   		      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 09:10:11 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 09:10:43 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		if (*(unsigned char *)(str + i) == (unsigned char)c)
			return ((void *)(str + i));
	return (NULL);
}