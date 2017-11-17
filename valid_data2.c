/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_data2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:40:33 by mkurchin          #+#    #+#             */
/*   Updated: 2017/09/28 11:40:34 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_pass_node(char *name, t_q *q)
{
	t_q *cur;

	cur = q;
	while (cur != NULL)
	{
		if (!strcmp(cur->name, name))
			return (0);
		cur = cur->next;
	}
	return (1);
}

int		ft_srch_ways(t_vrtx *vrtx, t_ls_rts **lst_rt, t_q *q, t_st *ptr)
{
	t_adj *adj_ptr;

	adj_ptr = vrtx->adj;
	vrtx->status = 3;
	enqueue(vrtx->name, &q, 0);
	while (adj_ptr != NULL)
	{
		if (!(ft_strcmp(adj_ptr->name, ptr->rm_end)))
			if (!ft_s_w2(lst_rt, ptr, &q, adj_ptr))
				return (0);
		if (is_pass_node(adj_ptr->name, q) && adj_ptr->lnk->adj != NULL
			&& vrtx->step < adj_ptr->lnk->step)
		{
			adj_ptr->lnk->status = 3;
			ft_srch_ways(adj_ptr->lnk, lst_rt, q, ptr);
		}
		adj_ptr = adj_ptr->next;
	}
	pop(&q);
	return (0);
}

int		is_correct_str_lnk(char **str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (i != 2)
		return (0);
	if (str[0][0] == 'L' || str[1][0] == 'L')
	{
		perror("Not valid string:");
		exit(0);
	}
	return (1);
}

void	ft_hndl_data(t_vrtx **vrtx, t_st *ptr)
{
	t_q			*q;
	t_ls_rts	*lst_rt;

	lst_rt = NULL;
	q = NULL;
	if ((!is_adj_st_end_rm(vrtx, ptr)))
	{
		perror("Error not found start or end link");
		exit(0);
	}
	ft_sort_vrtx(vrtx, ptr);
	enqueue((*vrtx)->name, &q, 0);
	(*vrtx)->step = 0;
	ft_by_gph(&lst_rt, vrtx, &q, 0);
	ft_srch_ways(*vrtx, &lst_rt, q, ptr);
	free_q(q);
	ft_select_ways(&lst_rt, ptr);
	ft_printf("\n");
	free_lst_rt(lst_rt);
}

int		is_str_lnk(char *line)
{
	char	**str;
	int		i;

	str = ft_strsplit2(line, '-');
	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	if (i != 2)
	{
		free_arr(str);
		return (0);
	}
	free_arr(str);
	return (1);
}
