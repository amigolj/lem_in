/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_ant2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 12:14:15 by mkurchin          #+#    #+#             */
/*   Updated: 2017/09/28 12:14:16 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		hndl_remain_ant(t_route *route, t_st *ptr, int *ant_finish)
{
	if (find_pst_queue_for_rplc_ant(&route, ptr))
		return (0);
	while (route->prev != NULL && *ant_finish != 0)
	{
		if (route->lem != 0 && route->next->lem == 0
			&& *ant_finish != 0)
			simple_rplc_ant(route, ptr, ant_finish);
		route = route->prev;
	}
	return (0);
}

void	free_lst_rt(t_ls_rts *lst_rt)
{
	while (lst_rt != NULL)
	{
		while (lst_rt->ptr_route != NULL)
		{
			free(lst_rt->ptr_route->name);
			free(lst_rt->ptr_route);
			lst_rt->ptr_route = lst_rt->ptr_route->next;
		}
		free(lst_rt);
		lst_rt = lst_rt->next;
	}
	free(lst_rt);
}

int		is_adj_st_end_rm(t_vrtx **vrtx, t_st *ptr)
{
	t_vrtx *ptr1;
	t_vrtx *ptr2;

	ptr1 = *vrtx;
	ptr2 = *vrtx;
	ptr1 = ft_srch_vrtx(&ptr1, ptr->rm_start);
	ptr2 = ft_srch_vrtx(&ptr2, ptr->rm_end);
	if (ptr1->adj == NULL || ptr2->adj == NULL)
		return (0);
	return (1);
}

int		is_cnt_len_rt_cnt_ant(t_st *ptr, t_ls_rts *ls_rts)
{
	int			cnt_rt;
	t_ls_rts	*head;

	head = ls_rts;
	cnt_rt = 0;
	while (head)
	{
		cnt_rt++;
		head = head->next;
	}
	head = ls_rts;
	if (ptr->cnt_ant <= cnt_rt)
		if (how_route_eq_rt(head) == cnt_rt)
			return (1);
	return (0);
}
