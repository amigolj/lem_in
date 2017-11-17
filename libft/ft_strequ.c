/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:41:54 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/01 19:50:46 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int fl;

	fl = 1;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*(unsigned char *)s1 != '\0' || *(unsigned char *)s2 != '\0')
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			fl = 0;
		s1++;
		s2++;
	}
	return (fl);
}
