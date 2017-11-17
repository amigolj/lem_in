/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:50:13 by mkurchin          #+#    #+#             */
/*   Updated: 2016/11/26 17:53:51 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *memptr, size_t num)
{
	size_t i;

	i = 0;
	if (!num)
		return ;
	while (i < num)
	{
		*((unsigned char *)memptr++) = 0;
		i++;
	}
}
