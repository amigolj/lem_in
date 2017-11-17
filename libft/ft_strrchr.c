/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 23:26:04 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/02 23:26:08 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*f;
	int		fl;

	fl = 0;
	while (*s != 0)
	{
		if (*(unsigned char *)s == (unsigned char)c)
		{
			f = (char *)s;
			fl = 1;
		}
		s++;
	}
	if (fl == 1)
		return (f);
	if (*(unsigned char *)s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
