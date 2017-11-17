/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_fl_num_u.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 22:07:14 by mkurchin          #+#    #+#             */
/*   Updated: 2017/04/11 22:07:15 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isunsn_t(t_var *p)
{
	if (p->type == 'o' || p->type == 'u'
		|| p->type == 'x' || p->type == 'X')
		return (1);
	return (0);
}

uintmax_t	ft_cast_long_u(void *arg, t_var *p)
{
	uintmax_t n;

	n = 0;
	if (p->length == 'h')
		return ((unsigned short)arg);
	if (p->length == 208)
		return ((unsigned char)arg);
	if (p->length == 'l')
		return ((unsigned long)arg);
	if (p->length == 216)
		return ((unsigned long long)arg);
	if (p->length == 'j')
		return ((uintmax_t)arg);
	if (p->length == 'z')
		return ((size_t)arg);
	if (p->length == 0 && (p->type == 'x' || p->type == 'X'))
		return ((unsigned int)arg);
	if (p->length == 'h')
		return ((unsigned short)arg);
	if (p->type == 'p')
		return ((long int)arg);
	n = (n == 0) ? (unsigned int)arg : n;
	return (n);
}

int			ft_cnt_digit_u(uintmax_t n, int b, t_var *p)
{
	int			i;
	uintmax_t	m;

	m = n;
	i = 1;
	while (n /= b)
		i++;
	i = (p->precision == 0 && p->dote == 1 && m == 0) ? 0 : i;
	return (i);
}

int			ft_toggle(t_var *p, intmax_t n)
{
	if (p->dote == 1 && p->precision == 0 && n == 0
		&& p->type == 111 && p->diez == 35)
	{
		write(1, "0", 1);
		return (1);
	}
	return (0);
}

int			ft_handle_fl_num_u(void *arg, t_var *p)
{
	int			cn_dig;
	int			print_chr;
	intmax_t	n;

	print_chr = 0;
	n = ft_cast_long_u(arg, p);
	cn_dig = ft_cnt_digit_u(n, ft_is_base(p), p);
	if (ft_toggle(p, n))
		return (1);
	if (p->flag == '-')
		print_chr += cs_minus_u(p, n, cn_dig, ft_is_base(p));
	else if (p->plus == '+')
		print_chr += cs_plus_u(p, n, cn_dig, ft_is_base(p));
	else if (p->zero == '0')
		print_chr += cs_zero_u(p, n, cn_dig, ft_is_base(p));
	else if (p->space == ' ')
		print_chr += cs_space_u(p, n, cn_dig, ft_is_base(p));
	else if (p->diez == '#')
		print_chr += cs_diez_u(p, n, cn_dig, ft_is_base(p));
	else if (p->flag == 0)
		print_chr += cs_null_u(p, n, cn_dig, ft_is_base(p));
	return (print_chr);
}
