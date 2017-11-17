/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 21:11:59 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/09 21:12:04 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_num_count(int n)
{
	int				i;
	int				sum;
	unsigned int	s;

	i = 0;
	sum = 0;
	if (n < 0)
	{
		s = -n;
		i++;
	}
	else
		s = n;
	while (s)
	{
		sum = s;
		sum %= 10;
		s /= 10;
		i++;
	}
	return (i);
}

static char		*ft_fill_ar(int n, int i, char **ar, unsigned int s)
{
	unsigned int	sum;

	sum = 0;
	if (n < 0)
		**ar = '-';
	if (n == 0)
	{
		**ar = '0';
		(*ar)++;
		**ar = '\0';
	}
	else
	{
		*ar += i;
		**ar = '\0';
	}
	while (s)
	{
		sum = s;
		sum %= 10;
		(*ar)--;
		**ar = sum + '0';
		s /= 10;
	}
	return (*ar);
}

char			*ft_itoa(int n)
{
	unsigned int	s;
	int				i;
	int				end;
	char			*ar;
	unsigned int	sum;

	sum = 0;
	ar = NULL;
	i = 0;
	end = 1;
	if (n < 0)
		s = -n;
	else
		s = n;
	i = ft_num_count(n);
	if (n == 0)
		end = 2;
	ar = (char *)malloc(sizeof(char) * i + end);
	if (!ar)
		return (NULL);
	ft_fill_ar(n, i, &ar, s);
	if (n <= 0)
		ar--;
	return (ar);
}
