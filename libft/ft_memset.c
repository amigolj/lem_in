/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:33:55 by mkurchin          #+#    #+#             */
/*   Updated: 2016/11/28 13:40:32 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		*((unsigned char *)memptr++) = (unsigned char)val;
		i++;
	}
	return (memptr -= i);
}
