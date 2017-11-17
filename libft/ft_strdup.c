/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 18:31:17 by mkurchin          #+#    #+#             */
/*   Updated: 2016/11/28 17:03:24 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dst;
	int		i;

	i = 0;
	len = ft_strlen((char*)s);
	dst = (char *)malloc(sizeof(char) * len + 1);
	if (!dst)
	{
		return (0);
	}
	while (i < len)
	{
		*((unsigned char *)dst) = *((unsigned char *)s);
		dst++;
		s++;
		i++;
	}
	*dst = '\0';
	return (dst -= i);
}
