/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_uitoa_base.c       	    	                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 10:17:59 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 10:19:05 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(unsigned int n, char *base)
{
	int				i;
	char			*output;
	unsigned int	temp;

	i = 1;
	temp = n;
	while (temp >= 16 && (temp / 16) > 0 && ++i)
		temp /= 16;
	output = malloc(sizeof(char) * (i + 1));
	output[i] = '\0';
	while (n >= 16)
	{
		output[--i] = base[n % 16];
		n /= 16;
	}
	output[--i] = base[n % 16];
	return (output);
}