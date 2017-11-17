/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hndl_fl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:51:26 by mkurchin          #+#    #+#             */
/*   Updated: 2017/04/11 20:51:28 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			cs_diez(t_var *p, intmax_t n, int cn_dig, int b)
{
	int		print_chr;
	int		len_s;
	char	*str;

	len_s = ft_is_sign(p, n) + ft_hndl_str_len(cn_dig, p);
	print_chr = 0;
	if (p->width != 0 && p->precision == 0)
		print_chr = ft_handl_wdth_num(p, len_s, ' ');
	else if (p->precision != 0)
		print_chr += ft_handl_wdth_num(p, len_s, ' ');
	ft_handl_precis_num(p, cn_dig);
	print_chr += ft_handl_sign(p, n);
	str = ft_itoa_base(n, b, p);
	print_chr += ft_putstr_n(str, cn_dig, p);
	free(str);
	return (print_chr);
}

int			cs_space(t_var *p, intmax_t n, int cn_dig, int b)
{
	int		print_chr;
	int		len_s;
	char	*str;

	len_s = ft_is_sign(p, n) + ft_hndl_str_len(cn_dig, p);
	print_chr = 0;
	if (p->sign == 0 && (p->type == 'd' || p->type == 'i'))
	{
		write(1, " ", 1);
		print_chr++;
	}
	if (p->width != 0 && p->precision == 0)
		print_chr += ft_handl_wdth_num(p, len_s, ' ');
	else if (p->precision != 0)
		print_chr += ft_handl_wdth_num(p, len_s, ' ');
	print_chr += ft_handl_sign(p, n);
	print_chr += ft_handl_precis_num(p, cn_dig);
	str = ft_itoa_base(n, b, p);
	print_chr += ft_putstr_n(str, cn_dig, p);
	free(str);
	return (print_chr);
}

int			cs_zero(t_var *p, intmax_t n, int cn_dig, int b)
{
	int		print_chr;
	int		len_s;
	char	*str;

	len_s = ft_is_sign(p, n) + ft_hndl_str_len(cn_dig, p);
	print_chr = 0;
	if (p->sign == 0 && p->space == ' ')
	{
		write(1, " ", 1);
		print_chr++;
	}
	print_chr += ft_handl_sign(p, n);
	if (p->width != 0 && p->precision == 0)
		print_chr += ft_handl_wdth_num(p, len_s, '0');
	else if (p->precision != 0)
		print_chr += ft_handl_wdth_num(p, len_s, ' ');
	print_chr += ft_handl_precis_num(p, cn_dig);
	str = ft_itoa_base(n, b, p);
	print_chr += ft_putstr_n(str, cn_dig, p);
	free(str);
	return (print_chr);
}

int			cs_plus(t_var *p, intmax_t n, int cn_dig, int b)
{
	int		print_chr;
	int		len_s;
	char	*str;

	len_s = ft_is_sign(p, n) + ft_hndl_str_len(cn_dig, p);
	print_chr = 0;
	if (p->width != 0 && p->zero == 0)
		print_chr += ft_handl_wdth_num(p, len_s, ' ');
	print_chr += ft_handl_sign(p, n);
	if (p->width != 0 && p->zero != 0 && p->plus != 0)
		print_chr += ft_handl_wdth_num(p, len_s, '0');
	print_chr += ft_handl_precis_num(p, cn_dig);
	str = ft_itoa_base(n, b, p);
	print_chr += ft_putstr_n(str, cn_dig, p);
	free(str);
	return (print_chr);
}

int			cs_minus(t_var *p, intmax_t n, int cn_dig, int b)
{
	int		print_chr;
	int		len_s;
	char	*str;

	len_s = ft_is_sign(p, n) + ft_hndl_str_len(cn_dig, p);
	print_chr = 0;
	print_chr += ft_handl_sign(p, n);
	print_chr += ft_handl_precis_num(p, cn_dig);
	str = ft_itoa_base(n, b, p);
	print_chr += ft_putstr_n(str, cn_dig, p);
	if (p->width != 0)
		print_chr += ft_handl_wdth_num(p, len_s, ' ');
	free(str);
	return (print_chr);
}
