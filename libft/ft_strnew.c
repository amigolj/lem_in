/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:49:56 by mkurchin          #+#    #+#             */
/*   Updated: 2016/11/30 21:01:53 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)malloc(sizeof(char) * size + 1);
	if (!s)
		return (NULL);
	while (i < (int)size)
	{
		*s = '\0';
		s++;
		i++;
	}
	*s = '\0';
	return (s -= i);
}
