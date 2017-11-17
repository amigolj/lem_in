/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hndl_sign_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 22:07:39 by mkurchin          #+#    #+#             */
/*   Updated: 2017/04/11 22:07:40 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_is_base(t_var *p)
{
	int b;

	b = 0;
	if (p->type == 'd' || p->type == 'D' ||
		p->type == 'u' || p->type == 'U' ||
		p->type == 'i')
		b = 10;
	if (p->type == 'o' || p->type == 'O')
		b = 8;
	if (p->type == 'x' || p->type == 'X' || p->type == 'p')
		b = 16;
	return (b);
}

int				ft_is_sign(t_var *p, intmax_t n)
{
	int fl;

	fl = 0;
	fl = (p->sign == 1) ? 1 : fl;
	fl = ((p->type == 'x' || p->type == 'X') &&
	p->sign == 1 && (intmax_t)n != 0) ? 0 : fl;
	fl = (p->plus == '+' && p->sign == 0) ? 1 : fl;
	fl = (p->diez == '#' && (p->type == 'x' || p->type == 'X')) ? 2 : fl;
	fl = ((p->diez == '#' && p->type == 'p') || p->type == 'p') ? 2 : fl;
	fl = (p->diez == '#' && (p->type == 'o' ||
	(p->type == 'O' && (intmax_t)n != 0))) ? 1 : fl;
	fl += (p->space == ' ' && p->sign == 0) ? 1 : 0;
	return (fl);
}

int				ft_is_sign_u(t_var *p, uintmax_t n)
{
	int fl;

	fl = 0;
	fl = (p->sign == 1) ? 1 : fl;
	fl = ((p->type == 'x' || p->type == 'X') &&
	p->sign == 1 && (intmax_t)n != 0) ? 0 : fl;
	fl = (p->plus == '+' && p->sign == 0) ? 1 : fl;
	fl = (p->diez == '#' && (p->type == 'x' || p->type == 'X')) ? 2 : fl;
	fl = ((p->diez == '#' && p->type == 'p') || p->type == 'p') ? 2 : fl;
	fl = (p->diez == '#' && (p->type == 'o' ||
	(p->type == 'O' && (intmax_t)n != 0))) ? 1 : fl;
	fl += (p->space == ' ' && p->sign == 0) ? 1 : 0;
	return (fl);
}

int				ft_handl_sign(t_var *p, intmax_t n)
{
	if (p->sign == 1 && !(ft_isunsn_t(p)))
		return ((int)write(1, "-", 1));
	if (p->plus == '+' && p->sign == 0 && (p->type == 'd' || p->type == 'i'))
		return ((int)write(1, "+", 1));
	if (p->diez == '#' && (p->type == 'x' || p->type == 'p') && n != 0)
		return ((int)write(1, "0x", 2));
	if (p->diez == '#' && p->type == 'X' && n != 0)
		return ((int)write(1, "0X", 2));
	if (p->diez == '#' && (p->type == 'o' || p->type == 'O') && (n != 0))
		return ((int)write(1, "0", 1));
	return ((p->type == 'p') ? (int)write(1, "0x", 2) : 0);
}

int				ft_handl_sign_u(t_var *p, uintmax_t n)
{
	if (p->sign == 1 && !(ft_isunsn_t(p)))
		return ((int)write(1, "-", 1));
	if (p->plus == '+' && p->sign == 0 && (p->type == 'd' || p->type == 'i'))
		return ((int)write(1, "+", 1));
	if (p->diez == '#' && (p->type == 'x' || p->type == 'p') && n != 0)
		return ((int)write(1, "0x", 2));
	if (p->diez == '#' && p->type == 'X' && n != 0)
		return ((int)write(1, "0X", 2));
	if (p->diez == '#' && (p->type == 'o' || p->type == 'O') && (n != 0))
		return ((int)write(1, "0", 1));
	return ((p->type == 'p') ? (int)write(1, "0x", 2) : 0);
}
