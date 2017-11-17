/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:00:48 by mkurchin          #+#    #+#             */
/*   Updated: 2017/03/22 13:00:49 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_mod(const char *format, t_var *ptr, void *var)
{
	if (ptr->type == 's' || ptr->type == 'S')
		return (ft_handle_fl_str(var, ptr));
	if (ptr->type == 'c')
		return (ft_handle_fl_str(var, ptr));
	if (ptr->type == 'C')
		return (ft_print_wchar(var));
	if (ptr->type == 'd' || ptr->type == 'D' ||
	ptr->type == 'i')
		return (ft_handle_fl_num(var, ptr));
	if (ptr->type == 'x' || ptr->type == 'X' ||
	ptr->type == 'o' || ptr->type == 'O' ||
	ptr->type == 'u' || ptr->type == 'U' ||
	ptr->type == 'p')
		return (ft_handle_fl_num_u(var, ptr));
	if (ptr->type == 0)
		return (ft_handle_fl_str((void *)format, ptr));
	return (0);
}
