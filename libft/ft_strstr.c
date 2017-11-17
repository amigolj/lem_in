/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:41:13 by mkurchin          #+#    #+#             */
/*   Updated: 2016/11/29 17:41:13 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int len;

	if (*little == 0)
		return ((char *)big);
	len = ft_strlen((char *)little);
	while (*big)
	{
		if (*big == *little)
		{
			if (!ft_strncmp(big, little, len))
				return ((char *)big);
		}
		big++;
	}
	return (NULL);
}
