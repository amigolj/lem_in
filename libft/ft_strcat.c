/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:05:44 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/02 17:37:22 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int i;

	i = 0;
	while (*s1)
	{
		s1++;
		i++;
	}
	while (*s2)
	{
		*s1 = *s2;
		s2++;
		s1++;
		i++;
	}
	*s1 = '\0';
	return (s1 -= i);
}
