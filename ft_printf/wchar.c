/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 22:35:34 by mkurchin          #+#    #+#             */
/*   Updated: 2017/04/03 22:35:35 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_4b(unsigned char *ptr, int *arr)
{
	int tmp;

	tmp = (*ptr) >> 6;
	*ptr <<= 2;
	arr[0] = (*ptr >> 2) + MASK1;
	ptr++;
	arr[2] = (*ptr >> 4);
	*ptr <<= 4;
	arr[1] += (*ptr >> 2) + tmp + MASK1;
	ptr++;
	arr[3] = *ptr >> 4;
	*ptr <<= 6;
	arr[2] += (*ptr >>= 2) + MASK1;
	ptr++;
	*ptr <<= 4;
	arr[3] += (*ptr >>= 4) + MASK4;
	return (4);
}

void	ft_print_utf8(int *c)
{
	int i;

	i = 4;
	while (i--)
		write(1, &c[i], 1);
}

int		ft_count_utf8(wchar_t *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		if (*str <= 127)
			i += 1;
		else if (*str <= 2047)
			i += 2;
		else if (*str <= 65535)
			i += 3;
		else if (*str <= 4194303)
			i += 4;
		str++;
	}
	return (i);
}

int		ft_hndl_msk(wchar_t *str)
{
	int				arr[5];
	int				i;
	int				test;
	unsigned char	*ptr;

	i = 0;
	test = (int)*str;
	ptr = (unsigned char *)&test;
	ft_bzero(arr, sizeof(int) * 5);
	if (*str <= 127)
	{
		arr[0] = *ptr;
		i = 1;
	}
	else if (*str <= 2047)
		i = ft_conv_2b(ptr, arr);
	else if (*str <= 65535)
		i = ft_conv_3b(ptr, arr);
	else if (*str <= 4194303)
		i = ft_conv_4b(ptr, arr);
	ft_print_utf8(arr);
	return (i);
}

int		ft_print_wchar(void *str)
{
	int				arr[5];
	int				i;
	int				test;
	unsigned char	*p;

	i = 0;
	test = (int)str;
	p = (unsigned char *)&test;
	ft_bzero(arr, sizeof(int) * 5);
	if ((int)str <= 127)
	{
		arr[0] = *p;
		i = 1;
	}
	else if ((int)str <= 2047)
		i = ft_conv_2b(p, arr);
	else if ((int)str <= 65535)
		i = ft_conv_3b(p, arr);
	else if ((int)str <= 4194303)
		i = ft_conv_4b(p, arr);
	ft_print_utf8(arr);
	return (i);
}
