/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hndl_num2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:38:47 by mkurchin          #+#    #+#             */
/*   Updated: 2017/04/12 15:38:48 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			cs_null(t_var *p, intmax_t n, int cn_dig, int b)
{
	int		print_chr;
	int		len_s;
	char	*str;

	len_s = ft_is_sign(p, n) + ft_hndl_str_len(cn_dig, p);
	print_chr = 0;
	if (p->width != 0 && p->precision == 0)
		print_chr = ft_handl_wdth_num(p, len_s, ' ');
	else if (p->precision != 0)
		print_chr = ft_handl_wdth_num(p, len_s, ' ');
	print_chr += ft_handl_sign(p, n);
	print_chr += ft_handl_precis_num(p, cn_dig);
	str = ft_itoa_base(n, b, p);
	print_chr += ft_putstr_n(str, cn_dig, p);
	free(str);
	return (print_chr);
}

intmax_t	ft_is_min_d(intmax_t n, t_var *p)
{
	if (n < 0)
	{
		n *= -1;
		p->sign = 1;
	}
	return (n);
}

intmax_t	ft_cast_long(void *arg, t_var *p)
{
	uintmax_t var;

	var = (uintmax_t)arg;
	p->sign = (var > LLONG_MAX) ? 1 : 0;
	if (p->length == 'l')
		return ((long)arg);
	if (p->length == 216)
		return ((long long)arg);
	if (p->length == 'h')
		return ((short)arg);
	if (p->length == 208)
		return ((signed char)arg);
	if (p->length == 'j')
		return ((intmax_t)arg);
	if (p->length == 'z')
		return ((size_t)arg);
	if (p->type == 'p')
		return ((long long)arg);
	return ((int)arg);
}
