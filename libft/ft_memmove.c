/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 21:18:03 by mkurchin          #+#    #+#             */
/*   Updated: 2016/11/26 23:12:13 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst1;
	char	*src1;

	src1 = (char*)src;
	dst1 = (char*)dst;
	i = -1;
	if (src >= dst)
	{
		while (++i < len)
			dst1[i] = src1[i];
		return (dst1);
	}
	else
	{
		len--;
		while ((int)len >= 0)
		{
			dst1[len] = src1[len];
			len--;
		}
		return (dst1);
	}
	return (dst1);
}
