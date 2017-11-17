/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:24:35 by mkurchin          #+#    #+#             */
/*   Updated: 2017/04/12 20:24:36 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_null_ptr(t_var *ptr)
{
	int *p;
	int i;

	p = &(ptr->flag);
	i = -1;
	while (++i < 11)
		if (p[i] != 0)
			return (0);
	return (1);
}

int		ft_srch_dot(char *str)
{
	char *ptr;

	ptr = str;
	while (ft_isdigit(*ptr))
		ptr--;
	if (*ptr == '.')
		return (0);
	else
		return (1);
}

void	ft_fill_zero(t_var *ptr)
{
	int *p;
	int i;

	p = &(ptr->flag);
	i = -1;
	while (++i < 11)
		p[i] = 0;
}
