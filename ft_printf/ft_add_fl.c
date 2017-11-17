/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_fl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:43:14 by mkurchin          #+#    #+#             */
/*   Updated: 2017/04/19 16:43:17 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hndl_dou(char *fl, t_var *ptr)
{
	if (*fl == 'D')
	{
		ptr->length = 'l';
		ptr->type = 'd';
	}
	else if (*fl == 'O')
	{
		ptr->length = 'l';
		ptr->type = 'o';
	}
	else if (*fl == 'U')
	{
		ptr->length = 'l';
		ptr->type = 'u';
	}
}

void	ft_add_fl(char *fl, int *p, t_var *ptr)
{
	if (*fl == '0' && *p == '-')
		return ;
	else if (*fl == 'D' || *fl == 'O' || *fl == 'U')
		ft_hndl_dou(fl, ptr);
	else if (*fl == '0')
		ptr->zero = *fl;
	else if (*fl == ' ')
		ptr->space = ' ';
	else if (*fl == '#')
		ptr->diez = '#';
	else if (*fl == '+')
		ptr->plus = '+';
	else
		*p = *fl;
}
