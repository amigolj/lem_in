/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:48:21 by mkurchin          #+#    #+#             */
/*   Updated: 2017/09/28 14:48:22 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_route(t_route *rt)
{
	while (rt != NULL)
	{
		free(rt->name);
		free(rt);
		rt = rt->next;
	}
	free(rt);
}

int		free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (1);
}

void	free_mem(t_st *ptr, t_fl *fl, t_vrtx *vrtx)
{
	free(ptr->rm_start);
	free(ptr->rm_end);
	free(ptr);
	free(fl);
	while (vrtx != NULL)
	{
		while (vrtx->adj != NULL)
		{
			free(vrtx->adj->name);
			free(vrtx->adj);
			vrtx->adj = vrtx->adj->next;
		}
		free(vrtx->adj);
		free(vrtx->name);
		free(vrtx->coord);
		free(vrtx->line);
		free(vrtx);
		vrtx = vrtx->next;
	}
	free(vrtx);
}

void	free_q(t_q *q)
{
	while (q != NULL)
	{
		free(q->name);
		free(q);
		q = q->next;
	}
}

int		is_correct_start_end_rm(t_st *ptr, t_fl *fl)
{
	if ((fl->cmd_start == 1 && ptr->pos_start < ptr->cnt_line
		&& fl->rm_start == 0) || (fl->cmd_end == 1
		&& ptr->pos_end < ptr->cnt_line && fl->rm_end == 0))
		return (1);
	else
		return (0);
}
