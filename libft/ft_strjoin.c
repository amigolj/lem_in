/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:46:03 by mkurchin          #+#    #+#             */
/*   Updated: 2016/11/30 23:16:41 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	size_t	s1_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s3 = (char *)malloc(sizeof(char) * s1_len + ft_strlen((char *)s2) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	while (*s1)
	{
		*s3++ = *s1++;
		i++;
	}
	while (*s2)
	{
		*s3++ = *s2++;
		i++;
	}
	*s3 = '\0';
	return (s3 -= i);
}
