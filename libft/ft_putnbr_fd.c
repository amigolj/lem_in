/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 03:03:53 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/04 03:03:59 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int s;

	if (n < 0)
	{
		s = -n;
		ft_putchar_fd('-', fd);
	}
	else
		s = n;
	if (s > 9)
	{
		ft_putnbr_fd(s / 10, fd);
		ft_putnbr_fd(s % 10, fd);
	}
	else
	{
		ft_putchar_fd(s += '0', fd);
	}
}
