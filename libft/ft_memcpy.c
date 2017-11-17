/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:33:46 by mkurchin          #+#    #+#             */
/*   Updated: 2016/11/26 17:46:51 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *ptrdst, const void *ptrsrc, size_t num)
{
	size_t i;

	i = 0;
	if (!num)
		return (ptrdst);
	while (i < num)
	{
		((unsigned char *)ptrdst)[i] = ((unsigned char *)ptrsrc)[i];
		i++;
	}
	return (ptrdst);
}
