/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_fl_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:51:54 by mkurchin          #+#    #+#             */
/*   Updated: 2017/04/11 20:51:55 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_handl_wdth_num(t_var *p, int len, char chr)
{
	int sum;
	int i;

	i = -1;
	sum = (p->width < len) ? 0 : p->width - len;
	while (++i < sum)
		write(1, &chr, 1);
	return (i);
}

int				ft_handl_precis_num(t_var *p, int cn_dig)
{
	int i;
	int len;

	i = -1;
	len = (cn_dig > p->precision) ? 0 : p->precision - cn_dig;
	while (++i < len)
		write(1, "0", 1);
	return (i);
}

int				ft_cnt_digit(intmax_t n, int b, t_var *p)
{
	int			i;
	intmax_t	m;

	m = n;
	i = 1;
	while (n /= b)
		i++;
	i = (p->precision == 0 && p->dote == 1 && m == 0) ? 0 : i;
	return (i);
}

int				ft_hndl_str_len(int cn_dig, t_var *p)
{
	int str_len;

	str_len = 0;
	str_len = (cn_dig > p->precision) ? cn_dig : p->precision;
	str_len = (p->precision == 0 && p->dote == 1) ? 0 : str_len;
	return (str_len);
}

int				ft_handle_fl_num(void *arg, t_var *p)
{
	int			cn_dig;
	int			s_len_s;
	int			print_chr;
	intmax_t	n;

	print_chr = 0;
	n = ft_cast_long(arg, p);
	n = ft_is_min_d(n, p);
	cn_dig = ft_cnt_digit(n, ft_is_base(p), p);
	s_len_s = ft_is_sign(p, n) + ft_hndl_str_len(cn_dig, p);
	if (p->flag == '-')
		print_chr += cs_minus(p, n, cn_dig, ft_is_base(p));
	else if (p->plus == '+')
		print_chr += cs_plus(p, n, cn_dig, ft_is_base(p));
	else if (p->zero == '0')
		print_chr += cs_zero(p, n, cn_dig, ft_is_base(p));
	else if (p->space == ' ')
		print_chr += cs_space(p, n, cn_dig, ft_is_base(p));
	else if (p->diez == '#')
		print_chr += cs_diez(p, n, cn_dig, ft_is_base(p));
	else if (p->flag == 0)
		print_chr += cs_null(p, n, cn_dig, ft_is_base(p));
	return (print_chr);
}
