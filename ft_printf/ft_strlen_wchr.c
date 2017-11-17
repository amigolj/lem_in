/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_wchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 16:15:40 by mkurchin          #+#    #+#             */
/*   Updated: 2017/04/02 16:15:44 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_wchr(void *arg, t_var *ptr)
{
	size_t		i;
	wchar_t		*str;
	char		*str2;

	i = 0;
	if (ptr->dote == 1 && ptr->precision == 0)
		return (0);
	if (ptr->type == 'S')
	{
		str = (wchar_t*)arg;
		return ((size_t)ft_count_utf8(str));
	}
	else if (ptr->type == 'C')
		return ((size_t)ft_cnt_byte_chr2((wchar_t)arg));
	str2 = (char*)arg;
	if (ptr->type == 'c')
		return (1);
	if (!str2)
		return (0);
	while (str2[i])
		i++;
	return (i);
}
