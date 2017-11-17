/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strenqu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:22:52 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/01 16:38:40 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		fl;
	size_t	i;

	i = 0;
	fl = 1;
	if (s1 == NULL || s2 == NULL)
		return (0);
	else if (s1 == NULL && s2 == NULL)
		return (0);
	while ((*(char *)s1 != '\0' || *(char *)s2 != '\0') && i < n)
	{
		if (*(char *)s1 != *(char *)s2)
			fl = 0;
		s1++;
		s2++;
		i++;
	}
	return (fl);
}
