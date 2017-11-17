/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_routes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:45:24 by mkurchin          #+#    #+#             */
/*   Updated: 2017/09/28 11:45:25 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_pst_queue_for_rplc_ant(t_route **route, t_st *ptr)
{
	if ((*route)->id == 1)
		*route = (*route)->next;
	while (*route != NULL)
	{
		if (!ft_strcmp((*route)->next->name, ptr->rm_end))
			break ;
		if (((*route)->lem != 0 && ((*route)->next->lem == 0)))
			break ;
		*route = (*route)->next;
	}
	return (0);
}

int		ft_count_elem(char **str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_exit(void)
{
	perror("Not valid string:");
	exit(0);
}

int		ft_s_w2(t_ls_rts **lst_rt, t_st *ptr, t_q **q, t_adj *adj_ptr)
{
	enqueue(ptr->rm_end, q, 0);
	ft_add_route(lst_rt);
	ft_add_node_route(lst_rt, *q);
	pop(q);
	adj_ptr->status = 4;
	adj_ptr->lnk->status = 4;
	if (!(adj_ptr = adj_ptr->next))
	{
		pop(q);
		return (0);
	}
	return (1);
}

int		is_correct_rm_coord(char **str)
{
	int	i;

	i = ft_count_elem(str);
	if (i != 3)
		ft_exit();
	if (str[0][0] == 'L')
		ft_exit();
	i = 0;
	while (str[1][i] != '\0')
	{
		if (!ft_isdigit(str[1][i]))
			ft_exit();
		i++;
	}
	i = 0;
	while (str[2][i] != '\0')
	{
		if (!ft_isdigit(str[2][i]))
			ft_exit();
		i++;
	}
	return (1);
}
