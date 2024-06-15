/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_append_char.c                          		                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/15 06:34:30 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/15 06:37:04 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append_char(char *input, char c)
{
	char	*output;
	int		size;
	int		i;

	size = 0;
	i = -1;
	if (input != NULL)
		size = ft_strlen(input);
	output = ft_calloc(size + 2, sizeof(char));
	if (input != NULL)
	{
		while (input[++i] != '\0')
			output[i] = input[i];
	}
	output[i] = c;
	output[i + 1] = '\0';
	free(input);
	return (output);
}