/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_printun_with_flags.c            		                              */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 09:40:14 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 09:43:01 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unf(unsigned int n, t_flags *flags, int *wc)
{
	char	*n_string;
	int		len;

	n_string = ft_uitoa(n);
	len = 0;
	if (flags->neg == 0 && flags->dot == 1 && flags->prec > 0
		&& (flags->width > flags->prec))
	{
		if ((int)ft_strlen(n_string) > flags->prec)
			len += print_dupe(' ', flags->width - (int)ft_strlen(n_string));
		else
			len += print_dupe(' ', flags->width - flags->prec);
		flags->width -= len;
	}
	*wc += print_dupe('0', flags->prec - (int)ft_strlen(n_string)) + len;
	if (flags->dot == 1)
	{
		flags->d = ' ';
		if (flags->width == 0)
			flags->width = flags->prec;
		if (n_string[0] != '0' && (flags->prec < (int)ft_strlen(n_string)))
			flags->prec = (int)ft_strlen(n_string);
	}
	print_stonf(n_string, flags, wc);
	free(n_string);
}