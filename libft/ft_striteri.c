/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:29:04 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/01 22:39:49 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	if (s && f)
	{
		i = 0;
		if (s == NULL)
			return ;
		while (*s)
		{
			f(i, s);
			s++;
			i++;
		}
	}
	else
		return ;
}
