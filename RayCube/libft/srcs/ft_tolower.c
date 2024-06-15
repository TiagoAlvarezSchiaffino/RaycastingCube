/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_tolower.c          	    	                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 10:16:01 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 10:16:42 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}