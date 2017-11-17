/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 03:52:48 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/10 03:52:50 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_max_num(int *ar, size_t len)
{
	size_t	i;
	size_t	max;

	i = 0;
	max = 0;
	if (!ar)
		return (0);
	max = ar[0];
	while (i < len)
	{
		if (max < (size_t)ar[i])
			max = ar[i];
		i++;
	}
	return (max);
}
