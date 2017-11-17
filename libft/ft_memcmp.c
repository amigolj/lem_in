/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 18:11:40 by mkurchin          #+#    #+#             */
/*   Updated: 2016/11/27 18:28:01 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s1) > *(unsigned char *)s2)
		{
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		}
		else if (*((unsigned char *)s1) < *(unsigned char *)s2)
		{
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		}
		s1++;
		s2++;
		i++;
	}
	return (0);
}
