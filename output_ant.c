/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 20:39:26 by mkurchin          #+#    #+#             */
/*   Updated: 2017/09/25 20:39:27 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_in_ant(t_route *route, t_st *ptr, int *i, int *ant_finish)
{
	if (!ft_strcmp(route->name, ptr->rm_start) &&
			!ft_strcmp(route->next->name, ptr->rm_end))
	{
		ptr->cnt_step++;
		ptr->cnt_ant--;
		(*ant_finish)--;
		ft_printf("\033[%i;mL%i\033[0m-\033[33;1;m%s\033[0m ",
			ptr->color, *i, route->next->name);
		(*i)++;
		return (1);
	}
	else if (route->next->lem == 0 && ptr->cnt_ant != 0)
	{
		route->next->lem = *i;
		ptr->cnt_ant--;
		ptr->cnt_step++;
		ft_printf("\033[%i;mL%i\033[0m-\033[33;1;m%s\033[0m ",
			ptr->color, *i, route->next->name);
		(*i)++;
		return (1);
	}
	return (0);
}

void	simple_rplc_ant(t_route *route, t_st *ptr, int *ant_finish)
{
	if (!(ft_strcmp(route->next->name, ptr->rm_end)))
	{
		ptr->cnt_step++;
		ft_printf("\033[%i;mLa%i\033[0m-\033[33;1;m%s\033[0m ",
			ptr->color, route->lem, route->next->name);
		route->lem = 0;
		(*ant_finish)--;
	}
	else
	{
		route->next->lem = route->lem;
		route->lem = 0;
		ft_printf("\033[%i;mLb%i\033[0m-\033[33;1;m%s\033[0m ",
			ptr->color, route->next->lem, route->next->name);
		ptr->cnt_step++;
	}
}

int		ft_start_end_rt(int ant_finish, t_st *ptr)
{
	int i;

	i = 1;
	while (ant_finish)
	{
		ptr->cnt_step++;
		ft_printf("\033[%i;mL%i\033[0m-\033[33;1;m%s\033[0m ",
			ptr->color, i, ptr->rm_end);
		ant_finish--;
		i++;
	}
	return (1);
}

void	replace_ant(t_route *route, t_st *ptr, int *ant_finish)
{
	while (route->prev != NULL && *ant_finish != 0)
	{
		if (!ft_strcmp(route->next->name, ptr->rm_end))
		{
			ptr->cnt_step++;
			ft_printf("\033[%i;mLd%i\033[0m-\033[33;1;m%s\033[0m ",
				ptr->color, route->lem, route->next->name);
			route->lem = 0;
			(*ant_finish)--;
		}
		else if (route->lem != 0 && route->next->lem == 0)
		{
			route->next->lem = route->lem;
			route->lem = 0;
			ptr->cnt_step++;
			ft_printf("\033[%i;mLe%i\033[0m-\033[33;1;m%s\033[0m ",
				ptr->color, route->next->lem, route->next->name);
			if (!(ft_strcmp(route->next->name, ptr->rm_end)))
				(*ant_finish)--;
		}
		route = route->prev;
	}
}

int		replace_lem(t_route *route, t_st *ptr, int *i, int *ant_finish)
{
	t_route *head;

	head = route;
	if (ft_in_ant(route, ptr, i, ant_finish))
		return (1);
	find_pst_queue_for_rplc_ant(&route, ptr);
	replace_ant(route, ptr, ant_finish);
	if (ptr->cnt_ant != 0)
	{
		head->next->lem = *i;
		ft_printf("\033[%i;mLc%i\033[0m-\033[33;1;m%s\033[0m ",
			ptr->color, head->next->lem, head->next->name);
		(*i)++;
		ptr->cnt_ant--;
		ptr->cnt_step++;
	}
	return (0);
}
