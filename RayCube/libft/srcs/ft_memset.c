/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_memset.c         		                                   		      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 09:14:28 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 09:15:00 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		*(unsigned char *)(str + i) = c;
	return (str);
}