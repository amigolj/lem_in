/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:43:12 by mkurchin          #+#    #+#             */
/*   Updated: 2016/11/29 16:40:53 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	if (*c1 == 0 || *c2 == 0)
		return (*c1 - *c2);
	if (*c1 == 0 && *c2 == 0)
		return (*c1 - *c2);
	while (*c1 != '\0' || *c2 != '\0')
	{
		if (*c1 > *c2)
			return (*c1 - *c2);
		else if (*c1 < *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
	return (0);
}
