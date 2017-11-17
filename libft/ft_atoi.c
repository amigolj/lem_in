/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:45:42 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/02 17:34:53 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_is_min(int *min, const char **str)
{
	if (**str == '+')
		*str += 1;
	else if (**str == '-')
	{
		*min = 1;
		*str += 1;
	}
}

int				ft_atoi(const char *str)
{
	int					i;
	unsigned long int	sum;
	int					min;

	sum = 0;
	i = 0;
	min = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	ft_is_min(&min, &str);
	while (*str >= 48 && *str <= 57)
	{
		sum = sum * 10 + (*str - '0');
		if (sum >= 9223372036854775807 && min == 0)
			return (-1);
		else if (sum > 9223372036854775807 && min == 1)
			return (0);
		i++;
		str++;
	}
	return ((min == 1) ? sum *= -1 : sum);
}
