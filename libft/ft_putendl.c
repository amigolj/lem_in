/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 22:13:22 by mkurchin          #+#    #+#             */
/*   Updated: 2016/11/30 18:54:50 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putendl(char const *s)
{
	size_t len;
	size_t i;

	i = 0;
	if (s == NULL)
		return ;
	len = ft_strlen((char *)s);
	while (i < len)
	{
		write(1, s, 1);
		s++;
		i++;
	}
	ft_putchar('\n');
}
