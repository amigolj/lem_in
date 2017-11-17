/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:47:10 by mkurchin          #+#    #+#             */
/*   Updated: 2016/11/30 15:01:01 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int s;

	if (n < 0)
	{
		s = -n;
		ft_putchar('-');
	}
	else
		s = n;
	if (s > 9)
	{
		ft_putnbr(s / 10);
		ft_putnbr(s % 10);
	}
	else
		ft_putchar(s + '0');
}
