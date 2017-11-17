/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 22:02:12 by mkurchin          #+#    #+#             */
/*   Updated: 2016/11/30 18:52:36 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_cnt_prcnt(const char **s)
{
	int			i;
	int			j;
	const char	*ptr;

	ptr = *s;
	j = 0;
	i = 0;
	while (*ptr)
	{
		if (*ptr != '%')
			break ;
		i++;
		ptr++;
	}
	j = ((i % 2) == 0) ? i / 2 : (i - 1) / 2;
	while (j)
	{
		write(1, "%", 1);
		j--;
	}
	return (i);
}

int		ft_putstr2(const char **s)
{
	int i;
	int j;

	i = 0;
	while (**s != '\0')
	{
		if (**s == '%' && i == 0 && *(*s + 1) == '\0')
		{
			(*s)++;
			return (0);
		}
		if (**s == '%' && *(*s + 1) == '%')
		{
			j = ft_cnt_prcnt(s);
			(*s) += (j % 2 != 0) ? j - 1 : j;
			i += ((j % 2) == 0) ? j / 2 : (j - 1) / 2;
		}
		if (**s == '%' || **s == '\0')
			break ;
		write(1, *s, 1);
		(*s)++;
		i++;
	}
	return (i);
}

int		ft_putstr3(const char **s, t_var *ptr)
{
	int i;
	int j;

	i = 0;
	ft_fill_zero(ptr);
	while (**s != '\0')
	{
		if (**s == '%' && i == 0 && *(*s + 1) == '\0')
		{
			(*s)++;
			return (0);
		}
		if (**s == '%' && *(*s + 1) == '%')
		{
			j = ft_cnt_prcnt(s);
			(*s) += (j % 2 != 0) ? j - 1 : j;
			i += ((j % 2) == 0) ? j / 2 : (j - 1) / 2;
		}
		if (**s == '%' || **s == '\0')
			break ;
		write(1, *s, 1);
		(*s)++;
		i++;
	}
	return (i);
}
