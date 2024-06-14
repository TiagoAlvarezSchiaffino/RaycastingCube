/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strtrim.c         	    	                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 10:09:25 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 10:12:40 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*output;

	i = 0;
	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && isset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && isset(s1[end - 1], set))
		end--;
	output = malloc(sizeof(char) * (end - start + 1));
	if (output == NULL)
		return (NULL);
	while (start < end)
		output[i++] = s1[start++];
	output[i] = '\0';
	return (output);
}