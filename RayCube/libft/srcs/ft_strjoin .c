/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strjoin.c            		                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 09:59:35 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 10:01:12 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	output = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (output == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		output[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		output[j++] = s2[i++];
	output[j] = '\0';
	return (output);
}