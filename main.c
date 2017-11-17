/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 13:32:12 by mkurchin          #+#    #+#             */
/*   Updated: 2017/06/30 13:32:14 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lem_in.h"

int		show_routes(t_ls_rts *lst_routes)
{
	int		cnt_routes;
	t_route	*cur;

	cnt_routes = 0;
	while (lst_routes != NULL)
	{
		cur = lst_routes->ptr_route;
		while (cur != NULL)
		{
			ft_printf("%s->", cur->name);
			cur = cur->next;
		}
		lst_routes = lst_routes->next;
		cnt_routes++;
		ft_printf("\n");
	}
	ft_printf("Total routes: %i\n\n", cnt_routes);
	return (cnt_routes);
}

void	color_set(t_st *ptr)
{
	ptr->color++;
	(ptr->color == 37) ? ptr->color = 31 : ptr->color;
}

void	ft_out_ant(int ant_finish, t_ls_rts **lst_rt, t_st *ptr, int i)
{
	int			fl;
	t_ls_rts	*cur;

	fl = 0;
	while (ant_finish)
	{
		cur = *lst_rt;
		if (!(ft_strcmp(cur->ptr_route->next->name, ptr->rm_end)))
			if (ft_start_end_rt(ant_finish, ptr))
				break ;
		while (cur != NULL && ant_finish >= 0)
		{
			if (ptr->cnt_ant >= cur->len || (cur->id == 1 && ptr->cnt_ant >= 0))
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
}

int		ft_select_ways(t_ls_rts **lst_rt, t_st *ptr)
{
	int ant_finish;
	int i;

	ant_finish = ptr->cnt_ant;
	i = 1;
	ft_sort_ways(lst_rt);
	ft_del_dubl(lst_rt);
	ft_printf("\n");
	if (ptr->shw_routes == 1)
		show_routes(*lst_rt);
	if (is_cnt_len_rt_cnt_ant(ptr, *lst_rt))
		if (out_eq(ptr, lst_rt, ant_finish, i))
			return (0);
	ft_out_ant(ant_finish, lst_rt, ptr, i);
	if (ptr->shw_cnt_step == 1)
		ft_printf("\ntotal turn: %i", ptr->cnt_step);
	return (0);
}

int		main(void)
{
	t_st	*ptr;
	t_fl	*fl;
	t_vrtx	*vrtx;
	t_map	*map;

	vrtx = NULL;
	ptr = NULL;
	map = NULL;
	ft_create_struct(&ptr, &fl);
	ft_parse_core(&vrtx, ptr, fl, &map);
	display_map_l(ptr, vrtx, map);
	ft_hndl_data(&vrtx, ptr);
	free_mem(ptr, fl, vrtx);
	return (0);
}
