/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:44:32 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/01 22:34:12 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_striter(char *s, void (*f)(char *))
{
	unsigned int	i;
	size_t			len;

	if (s && f)
	{
		len = ft_strlen(s);
		i = 0;
		while (i < len)
		{
			f(&s[i]);
			i++;
		}
	}
	else
		return ;
}
