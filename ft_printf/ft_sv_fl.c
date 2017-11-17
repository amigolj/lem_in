/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sv_fl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:14:00 by mkurchin          #+#    #+#             */
/*   Updated: 2017/03/29 18:14:05 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hndl_width_fl(char *fl, t_var *p)
{
	int w;

	w = 0;
	while (ft_isdigit(*fl))
		fl--;
	fl++;
	p->zero = (*fl == '0') ? '0' : p->zero;
	w = ft_atoi(fl);
	p->width = (w != 0) ? w : p->width;
}

int		ft_sv_fl(char *fl, int i, t_var *p)
{
	int *c;

	c = &(p->flag);
	if (ft_isdigit(*fl) && ft_srch_dot(fl) == 1)
		ft_hndl_width_fl(fl, p);
	else if (ft_isdigit(*fl) && !(ft_srch_dot(fl)))
		return (0);
	else if (*fl == '.')
	{
		p->precision = ft_atoi(++fl);
		p->dote = 1;
	}
	else if ((*fl == 'h' || *fl == 'l')
	&& (*(fl + 1) == *fl || *(fl - 1) == *fl))
	{
		if (p->length != 104 && p->length != 108)
			p->length = (*fl) * 2;
	}
	else
	{
		if (!(ft_srch(fl, p)))
			ft_add_fl(fl, &c[i], p);
	}
	return (0);
}
