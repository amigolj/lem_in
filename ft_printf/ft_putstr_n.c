/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 22:34:19 by mkurchin          #+#    #+#             */
/*   Updated: 2017/04/03 22:34:21 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wht_byte(wchar_t *str, int len)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		if ((len - i) < ft_cnt_byte_chr(str + 1))
			break ;
		i += ft_hndl_msk(str);
		str++;
	}
	return (i);
}

int		ft_is_type_not_null(char *str, char *arg, t_var *ptr, int len)
{
	int		i;
	wchar_t	tmp;

	i = 0;
	if (str == NULL)
		return (0);
	if (ptr->type == 'S')
		return (ft_wht_byte((wchar_t *)arg, len));
	else if (ptr->type == 'C')
	{
		ft_strlen_wchr(arg, ptr);
		tmp = (wchar_t)arg;
		return (ft_hndl_msk(&tmp));
	}
	if (ptr->type == 'c' || ptr->type == 0)
		return ((int)write(1, &str, 1));
	if (ptr->type == 0)
		return ((int)write(1, &str, 1));
	while (i < len)
	{
		write(1, str, 1);
		str++;
		i++;
	}
	return (i);
}

int		ft_putstr_n(void *arg, int len, t_var *ptr)
{
	int		i;
	char	*str;

	str = arg;
	i = 0;
	if (str == NULL && ptr->type == 's')
		return ((int)write(1, "(null)", 6));
	if ((char)arg == 0 && ptr->type == 'c')
		return ((int)write(1, &(arg), 1));
	else if (str == NULL && ptr->type == 'c')
		return (1);
	if (ptr->type != 0)
		return (ft_is_type_not_null(str, arg, ptr, len));
	else
	{
		if (str == NULL)
			return (0);
		write(1, str, 1);
		i++;
		return (i);
	}
}
