/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_sf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:00:01 by mkurchin          #+#    #+#             */
/*   Updated: 2017/03/23 19:00:02 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_toggle_s2(t_var *ptr)
{
	if (ptr->type == 's' && ptr->length == 'l')
		ptr->type = 'S';
	if (ptr->type == 'c' && ptr->length == 'l')
		ptr->type = 'C';
}

int		ft_toggle_s(void *arg, t_var *ptr)
{
	if ((char *)arg == NULL && ptr->precision == 0 && ptr->type == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if ((char *)arg == NULL && ptr->precision == 0 && ptr->type == 'S')
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (0);
}

int		ft_handl_wdth_str(t_var *ptr, int len, char chr)
{
	int sum;
	int i;

	i = -1;
	sum = (ptr->width < len) ? 0 : ptr->width - len;
	while (++i < sum)
		write(1, &chr, 1);
	return (i);
}

int		ft_handl_precis_str(t_var *ptr, void *arg, int len)
{
	wchar_t *str;
	int		p_len;

	str = (wchar_t*)arg;
	if (ptr->type == 'S')
	{
		p_len = (len < ptr->precision) ? len :
				ft_valid_byte(str, ptr->precision);
		return (p_len);
	}
	p_len = (len < ptr->precision) ? len : ptr->precision;
	return (p_len);
}

int		ft_handle_fl_str(void *arg, t_var *ptr)
{
	int len_chr;
	int print_chr;

	print_chr = 0;
	ft_toggle_s2(ptr);
	if (ptr->type != 0 && ptr->type != 'C')
	{
		if (ft_toggle_s(arg, ptr))
			return (6);
		len_chr = ft_strlen_wchr(arg, ptr);
	}
	else
		len_chr = 1;
	if (ptr->flag == '-')
		print_chr += hndl_min_s(arg, ptr, len_chr, ft_strlen_wchr(arg, ptr));
	else if (ptr->flag == '0')
		hndl_zero_s(arg, ptr, len_chr, ft_strlen_wchr(arg, ptr));
	else if (ptr->flag == '+')
		ft_putstr((char*)arg);
	else if (ptr->flag == ' ')
		print_chr += ft_putstr_n(arg, len_chr, ptr);
	else if (ptr->flag == 0)
		print_chr += hndl_null_s(arg, ptr, len_chr);
	return (print_chr);
}
