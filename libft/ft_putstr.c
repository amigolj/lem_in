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

#include "libft.h"

void		ft_putstr(char const *s)
{
	size_t len;
	size_t i;

	if (s == NULL)
		return ;
	len = ft_strlen((char *)s);
	i = 0;
	while (i < len)
	{
		write(1, s, 1);
		s++;
		i++;
	}
}
