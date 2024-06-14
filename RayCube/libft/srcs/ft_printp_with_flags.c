/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_printp_with_flags.c            		                                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/14 09:35:01 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 09:36:27 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pf(unsigned long string_addr, t_flags *flags, int *wc)
{
	char	*n;
	int		len;

	n = ft_ultoa_base(string_addr);
	len = 0;
	if (flags->neg == 0 && (flags->dot == 1 && flags->prec == 1)
		&& flags->width > flags->prec)
	{
		if (flags->prec < (int)ft_strlen(n))
			len += print_dupe(' ', flags->width - (int)ft_strlen(n));
		else
			len += print_dupe(' ', flags->width - flags->prec);
		flags->width -= len;
	}
	*wc += len;
	wc += print_dupe('0', flags->prec - (int)ft_strlen(n));
	if (flags->dot == 1)
		flags->d = ' ';
	if (flags->dot == 1 && flags->width == 0)
		flags->width = flags->prec;
	if (flags->dot == 1 && (flags->prec < (int)ft_strlen(n)) && n[0 != '0'])
		flags->prec = (int)ft_strlen(n);
	print_stonf(n, flags, wc);
	free(n);
}