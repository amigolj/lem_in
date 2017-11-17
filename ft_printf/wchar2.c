/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:51:42 by mkurchin          #+#    #+#             */
/*   Updated: 2017/04/13 14:51:44 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_cnt_byte_chr2(wchar_t chr)
{
	if (chr <= 127)
		return (1);
	else if (chr <= 2047)
		return (2);
	else if (chr <= 65535)
		return (3);
	else if (chr <= 4194303)
		return (4);
	return (0);
}

int		ft_cnt_byte_chr(wchar_t *str)
{
	if (*str <= 127)
		return (1);
	else if (*str <= 2047)
		return (2);
	else if (*str <= 65535)
		return (3);
	else if (*str <= 4194303)
		return (4);
	return (0);
}

int		ft_valid_byte(wchar_t *str, int len)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		if ((len - i) < ft_cnt_byte_chr(str + 1))
			break ;
		i += ft_cnt_byte_chr(str);
		str++;
	}
	return (i);
}

int		ft_conv_2b(unsigned char *ptr, int *arr)
{
	int tmp;

	tmp = *ptr >> 6;
	*ptr <<= 2;
	arr[0] = (*ptr >>= 2) + MASK1;
	ptr++;
	*ptr <<= 3;
	arr[1] = ((*ptr >>= 1) + tmp) + MASK2;
	return (2);
}

int		ft_conv_3b(unsigned char *ptr, int *arr)
{
	int tmp;

	tmp = *ptr >> 6;
	*ptr <<= 2;
	arr[0] = (*ptr >>= 2) + MASK1;
	ptr++;
	arr[2] = (*ptr >> 4);
	*ptr <<= 4;
	arr[1] = (*ptr >>= 2) + tmp + MASK1;
	ptr++;
	*ptr <<= 4;
	arr[2] += (*ptr) + MASK3;
	return (4);
}
