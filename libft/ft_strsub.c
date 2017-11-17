/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 23:12:44 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/01 11:39:47 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc(len + 1);
	if (s == NULL)
		return (NULL);
	if (!s2)
		return (NULL);
	while (i < (int)len)
	{
		*s2 = s[start];
		i++;
		start++;
		s2++;
	}
	*s2 = '\0';
	return (s2 -= i);
}
