/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hndl_route3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 00:06:36 by mkurchin          #+#    #+#             */
/*   Updated: 2017/09/29 00:06:38 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t	ft_strlen2(const char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int		how_route_eq_rt(t_ls_rts *head)
{
	int fl;
	int len;
	int i;

	i = 0;
	len = 0;
	fl = 0;
	while (head)
	{
		if (fl == 0)
		{
			len = head->len;
			fl = 1;
		}
		if (fl == 1 && len == head->len)
			i++;
		head = head->next;
	}
	return (i);
}

int		out_eq(t_st *ptr, t_ls_rts **lst_rt, int ant_finish, int i)
{
	t_ls_rts	*cur;
	int			fl;

	fl = 0;
	while (ant_finish)
	{
		cur = *lst_rt;
		while (cur != NULL && ant_finish >= 0)
		{
			if (ptr->cnt_ant > 0)
			{
				replace_lem(cur->ptr_route, ptr, &i, &ant_finish);
				fl = 1;
			}
			if (fl == 0)
				hndl_remain_ant(cur->ptr_route, ptr, &ant_finish);
			fl = 0;
			cur = cur->next;
		}
		color_set(ptr);
		ft_printf("\n");
	}
	if (ptr->shw_cnt_step == 1)
		ft_printf("\ntotal turn: %i", ptr->cnt_step);
	return (1);
}

int		add_ln_map(t_map **map, char *line)
{
	t_map *head;

	if (*map == NULL)
	{
		*map = (t_map*)malloc(sizeof(t_map));
		(*map)->line = strdup(line);
		(*map)->next = NULL;
		return (0);
	}
	head = *map;
	while (head->next != NULL)
		head = head->next;
	head->next = (t_map*)malloc(sizeof(t_map));
	head->next->line = ft_strdup(line);
	head->next->next = NULL;
	return (0);
}
