/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_dprintf_utils.c                                		                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 08:47:10 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 08:52:45 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ftdpf_width(int fd, int width, char c)
{
	int	i;

	i = 0;
	while (i < width)
	{
		write(fd, &c, 1);
		i++;
	}
	return (i);
}

void	ftdpf_get_neg(long *n, int *neg)
{
	if (*n < 0)
	{
		*neg = 1;
		*n *= -1;
	}
	else
		*neg = 0;
}

int	ftdpf_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ftdpf_get_len_base(unsigned long n, int base_len)
{
	int	count;

	count = 0;
	if (!n)
		return (1);
	while (n > 0)
	{
		n /= base_len;
		count++;
	}
	return (count);
}

void	ftdpf_print_base(int fd, unsigned long n, char *base)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (!n)
		write(fd, base, 1);
	else
	{
		if (n >= base_len)
		{
			ftdpf_print_base(fd, n / base_len, base);
			ftdpf_print_base(fd, n % base_len, base);
		}
		else
			write(fd, base + n, 1);
	}
}