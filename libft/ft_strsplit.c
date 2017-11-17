/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:08:33 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/09 20:17:30 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_ch(char *s, char c)
{
	int j;

	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c)
			{
				s++;
				j++;
			}
			return (j);
		}
		s++;
	}
	return (j);
}

static int	ft_cw(char *s, char c)
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

char		**ft_strsplit(char const *s, char c)
{
	char	**b;
	int		v[3];

	if (s == NULL)
		return (0);
	v[0] = ft_cw((char *)s, c);
	v[2] = ft_strlen((char *)s);
	if (!(b = (char **)malloc(sizeof(char *) * (v[0] + 1))))
		return (0);
	b[v[0]] = NULL;
	s += (v[2] -= 1);
	while (v[2] >= 0)
	{
		if ((*s != c && *(s - 1) == c) || (*s != c && v[2] == 0))
		{
			v[1] = ft_count_ch((char *)s, c);
			if (!(b[--v[0]] = (char *)malloc(sizeof(char) * v[1] + 1)))
				return (0);
			if (!(b[v[0]] = ft_strsub(s - v[2], v[2], v[1])))
				return (0);
		}
		v[2]--;
		s--;
	}
	return (b);
}
