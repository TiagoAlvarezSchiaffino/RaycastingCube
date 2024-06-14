/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strlen.c         	    	                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 10:01:48 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 10:02:20 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (*str++)
		length++;
	return (length);
}