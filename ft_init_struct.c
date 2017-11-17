/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 17:35:10 by mkurchin          #+#    #+#             */
/*   Updated: 2017/07/05 17:35:12 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_init_struct(t_st **ptr, t_fl **fl)
{
	(*ptr)->color = 31;
	(*ptr)->shw_routes = 0;
	(*ptr)->shw_cnt_step = 0;
	(*ptr)->cnt_step = 0;
	(*ptr)->cnt_ant = -1;
	(*ptr)->pos_start = -1;
	(*ptr)->pos_end = -1;
	(*ptr)->cnt_line = 0;
	(*ptr)->cnt_rm = 0;
	(*ptr)->cnt_lnk = 0;
	(*ptr)->rm_start = NULL;
	(*ptr)->rm_end = NULL;
	(*fl)->ant = 0;
	(*fl)->rm_start = 0;
	(*fl)->rm_end = 0;
	(*fl)->cmd_end = 0;
	(*fl)->cmd_start = 0;
	(*fl)->end_link = 0;
	(*fl)->link = 0;
	(*fl)->crt_lst_rm = 0;
}

void		ft_create_struct(t_st **ptr, t_fl **fl)
{
	if (*ptr == NULL)
	{
		*ptr = (t_st*)malloc(sizeof(t_st));
		*fl = (t_fl*)malloc(sizeof(t_fl));
		ft_init_struct(ptr, fl);
	}
}

static int	ft_count_ch(char *s, char c)
{
	int j;

	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			while ((*s) != c && *s)
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

char		**ft_strsplit2(char const *s, char c)
{
	char	**b;
	int		v[3];

	if (s == NULL)
		return (0);
	v[0] = ft_cw((char *)s, c);
	v[2] = ft_strlen((char *)s);
	if (!(b = (char**)malloc(sizeof(char *) * (v[0] + 1))))
		return (0);
	b[v[0]] = NULL;
	s += (v[2] -= 1);
	while (v[2] >= 0)
	{
		if ((*s != c && *(s - 1) == c) || (*s != c && v[2] == 0))
		{
			v[1] = ft_count_ch((char *)s, c);
			if (!(b[--v[0]] = ft_strsub(s - v[2], v[2], v[1])))
				return (0);
		}
		v[2]--;
		s--;
	}
	return (b);
}
