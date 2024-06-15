/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strncmp.c         	    	                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 10:04:02 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/15 06:22:53 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;
	int		diff;

	index = -1;
	diff = 0;
	if (n == 0 || (!s1 && !s2))
		return (0);
	if (!s1)
		return (s2[0]);
	if (!s2)
		return (s1[0]);
	while (++index < n && diff == 0 && s1[index] != '\0' && s2[index] != '\0')
		diff = (unsigned char)s1[index] - (unsigned char)s2[index];
	if (index < n && diff == 0 && (s1[index] == '\0' || s2[index] == '\0'))
			diff = (unsigned char)s1[index] - (unsigned char)s2[index];
	return (diff);
}