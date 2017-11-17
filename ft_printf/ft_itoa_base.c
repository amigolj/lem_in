/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:12:05 by mkurchin          #+#    #+#             */
/*   Updated: 2017/03/30 17:12:07 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_base(uintmax_t arg, int base, t_var *ptr)
{
	int					i;
	unsigned long long	value;
	unsigned long long	num;
	char				*s;
	char				*hex;

	hex = (ptr->type == 'x') ? "0123456789abcdef" : '\0';
	hex = (ptr->type == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	i = 1;
	value = arg;
	num = value;
	while (num /= base)
		i++;
	if ((s = (char*)malloc(sizeof(char) * i + 1)) == 0)
		return (NULL);
	s[i] = 0;
	s[0] = (value == 0) ? '0' : s[0];
	num = value;
	while (num)
	{
		s[--i] = hex[num % base];
		num /= base;
	}
	return (s);
}
