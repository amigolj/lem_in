/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hndl_num_u2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:50:17 by mkurchin          #+#    #+#             */
/*   Updated: 2017/04/13 15:50:18 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cs_minus_u(t_var *p, uintmax_t n, int cn_dig, int b)
{
	int print_chr;
	int len_s;

	len_s = ft_is_sign(p, n) + ft_hndl_str_len(cn_dig, p);
	print_chr = 0;
	print_chr += ft_handl_sign_u(p, n);
	print_chr += ft_handl_precis_num(p, cn_dig);
	print_chr += ft_putstr_n(ft_itoa_base(n, b, p), cn_dig, p);
	if (p->width != 0)
		print_chr += ft_handl_wdth_num(p, len_s, ' ');
	return (print_chr);
}
