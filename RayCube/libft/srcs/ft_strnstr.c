/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strnstr.c         	    	                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 10:06:12 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 10:07:53 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (to_find[0] == 0)
		return ((char *)str);
	while (str[++i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] && to_find[j]
			&& i + j < len && str[i + j] == to_find[j])
			j++;
		if (!to_find[j])
			return ((char *)(str + i));
	}
	return (NULL);
}