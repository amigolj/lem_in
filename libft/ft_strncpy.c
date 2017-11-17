/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:27:52 by mkurchin          #+#    #+#             */
/*   Updated: 2016/11/30 17:30:33 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	int		len_src;

	len_src = ft_strlen((char *)src);
	i = 0;
	while (*src && i < len)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		dst++;
		src++;
		i++;
	}
	while (len_src < (int)len)
	{
		*dst = '\0';
		dst++;
		len_src++;
		i++;
	}
	return (dst -= i);
}
