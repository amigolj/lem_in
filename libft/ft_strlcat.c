/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 22:17:34 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/04 22:17:37 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_dst;
	size_t len_src;
	size_t ii;
	size_t num_b;

	ii = 0;
	len_dst = ft_strlen((char *)dst);
	len_src = ft_strlen((char *)src);
	if (len_dst < size)
	{
		num_b = size - len_dst;
		if ((size - len_dst) == 1)
			return (len_dst + len_src);
		dst += len_dst;
		while (ii < num_b - 1)
		{
			*dst++ = *src++;
			ii++;
		}
		*dst = '\0';
		return (len_src + len_dst);
	}
	else if (len_dst >= size)
		return (len_src + size);
	return (0);
}
