/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 22:20:33 by mkurchin          #+#    #+#             */
/*   Updated: 2017/04/18 22:20:35 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_handle(const char **format, t_var *ptr)
{
	if (**format == '%' && *((*format) + 1) == '%')
	{
		ft_putstr2(format);
		return (1);
	}
	if (**format == '%' && *((*format) + 1) == '\0')
		return (1);
	if (**format == '%' && ft_is_null_ptr(ptr) == 1)
		(*format)++;
	return (1);
}

int			ft_handle_no_fl(const char **format, t_var *ptr, void *var)
{
	int print_chr;

	print_chr = 0;
	print_chr += ft_print_mod(*format, ptr, var);
	(*format)++;
	print_chr += ft_putstr3(format, ptr);
	ft_fill_zero(ptr);
	return (print_chr);
}

t_var		*ft_crt_struct(void)
{
	t_var *ptr;

	ptr = (t_var*)malloc(sizeof(t_var));
	ft_fill_zero(ptr);
	return (ptr);
}

int			ft_handle_arg(const char **format, t_var *ptr, void *var)
{
	int print_chr;

	print_chr = 0;
	(*format)++;
	print_chr += ft_print_mod(*format, ptr, var);
	return (print_chr);
}

int			ft_printf(const char *format, ...)
{
	t_var	*ptr;
	void	*var;
	int		print_chr;
	va_list ap;

	ptr = ft_crt_struct();
	print_chr = ft_putstr2(&format);
	va_start(ap, format);
	while (*format != '\0' && ft_handle(&format, ptr))
	{
		if (ft_parse((char *)format, ptr))
		{
			var = (void*)va_arg(ap, void*);
			print_chr += ft_handle_arg(&format, ptr, var);
			print_chr += ft_putstr3(&format, ptr);
		}
		else if (ft_srch(format, ptr))
			print_chr += ft_handle_no_fl(&format, ptr, var);
		if (*format == '\0')
			break ;
		format++;
	}
	va_end(ap);
	free(ptr);
	return (print_chr);
}
