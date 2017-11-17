/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:42:45 by mkurchin          #+#    #+#             */
/*   Updated: 2016/11/29 16:39:44 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	if (*s1 == 0 || *s2 == 0)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	if (*s1 == 0 && *s2 == 0)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	while ((*s1 != '\0' || *s2 != '\0') && i < n)
	{
		if (*(unsigned char *)s1 > *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		else if (*(unsigned char *)s1 < *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		i++;
	}
	return (*(unsigned char *)--s1 - *(unsigned char *)--s2);
}
