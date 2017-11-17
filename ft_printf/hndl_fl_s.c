/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hndl_fl_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 21:01:05 by mkurchin          #+#    #+#             */
/*   Updated: 2017/04/12 21:01:06 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			hndl_min_s(void *arg, t_var *p, int l_chr, int len_byte)
{
	int print_chr;

	print_chr = 0;
	if (p->length == 'h')
	{
		ft_handl_precis_str(p, arg, l_chr);
		print_chr += ft_putstr_n(arg, len_byte, p);
		if (p->width != 0)
			print_chr += ft_handl_wdth_str(p, l_chr, ' ');
	}
	else
	{
		if (p->dote != 0)
			len_byte = ft_handl_precis_str(p, arg, l_chr);
		print_chr += ft_putstr_n(arg, len_byte, p);
		if (p->width != 0)
			print_chr += ft_handl_wdth_str(p, len_byte, ' ');
	}
	return (print_chr);
}

int			hndl_null_s(void *arg, t_var *p, int l_chr)
{
	int print_chr;

	print_chr = 0;
	if (p->precision != 0)
		l_chr = ft_handl_precis_str(p, arg, l_chr);
	if (p->width != 0 && p->zero == 0)
		print_chr += ft_handl_wdth_str(p, l_chr, ' ');
	else if (p->width != 0 && p->zero == '0')
		print_chr += ft_handl_wdth_str(p, l_chr, '0');
	print_chr += ft_putstr_n(arg, l_chr, p);
	return (print_chr);
}

void		hndl_zero_s(void *arg, t_var *p, int l_chr, int len_byte)
{
	ft_handl_precis_str(p, arg, l_chr);
	if (p->width != 0)
		ft_handl_wdth_str(p, l_chr, '0');
	ft_putstr_n(arg, len_byte, p);
}
