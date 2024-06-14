/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_bzero.c                                        		                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 08:34:20 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 08:34:53 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dst, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		*(unsigned char *)(dst + i) = '\0';
}