/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strdup.c            		                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 09:55:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/15 06:20:16 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		counter;
	int		index;

	if (!src)
		return (NULL);
	counter = 0;
	while (src[counter] != '\0')
		counter++;
	copy = malloc(sizeof(char) * (counter + 1));
	if (copy == NULL)
		return (0);
	index = -1;
	while (src[++index] != '\0')
		copy[index] = src[index];
	copy[index] = '\0';
	return (copy);
}