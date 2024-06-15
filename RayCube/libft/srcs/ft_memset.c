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
/*   Updated: 2024/06/15 06:17:25 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = -1;
	if (!str)
		return (str);
	while (++i < n)
		*(unsigned char *)(str + i) = c;
	return (str);
}