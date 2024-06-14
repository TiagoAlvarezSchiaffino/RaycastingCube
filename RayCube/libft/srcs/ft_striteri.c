/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_striteri.c            		                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 09:58:44 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 09:59:27 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i] != '\0')
		(*f)(i, &s[i]);
}