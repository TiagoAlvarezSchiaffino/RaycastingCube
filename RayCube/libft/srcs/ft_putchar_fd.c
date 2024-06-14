/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_putchar_fd.c            		                                      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 09:43:16 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 09:43:30 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}