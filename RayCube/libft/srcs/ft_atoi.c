/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_atoi.c                                         		                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 08:33:07 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 08:34:15 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	check_max(int value)
{
	if (value == -1)
		return (0);
	return (-1);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		value;
	long	number;
	int		counter;

	i = 0;
	value = 1;
	number = 0;
	counter = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			value = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i++] - 48);
		counter++;
	}
	return (number * value);
}