/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 03:48:31 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/10 03:48:33 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_w(char *s, char c)
{
	int	count;
	int	fl;

	fl = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && fl == 0)
		{
			fl = 1;
			count++;
		}
		else if (*s == c)
			fl = 0;
		s++;
	}
	return (count);
}
