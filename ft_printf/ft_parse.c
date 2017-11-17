/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 22:33:40 by mkurchin          #+#    #+#             */
/*   Updated: 2017/04/03 22:33:42 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_srch(const char *format, t_var *ptr)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (g_spec_form[i] != NULL)
	{
		j = 0;
		while (g_spec_form[i][j])
		{
			if (*format == g_spec_form[i][j])
				return (0);
			j++;
		}
		i++;
	}
	if (ptr->type == 0)
		return (1);
	return (1);
}

void	ft_init(void)
{
	g_spec_form[0] = "-+ #0";
	g_spec_form[1] = "0123456789";
	g_spec_form[2] = ".";
	g_spec_form[3] = "hhhllljz";
	g_spec_form[4] = "sSpdDioOuUxXcC";
	g_spec_form[5] = NULL;
}

int		ft_parse(char *format, t_var *ptr)
{
	int	i;
	int	jj;

	i = 0;
	ft_init();
	while (i < 5)
	{
		jj = 0;
		while (g_spec_form[i][jj] != '\0')
		{
			if ((g_spec_form[i][jj] == *format && i == 4))
			{
				ft_sv_fl(format, i, ptr);
				return (1);
			}
			if (g_spec_form[i][jj] == *format)
				ft_sv_fl(format, i, ptr);
			jj++;
		}
		i++;
	}
	return (0);
}
