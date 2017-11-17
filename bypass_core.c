/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bypass_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 20:46:01 by mkurchin          #+#    #+#             */
/*   Updated: 2017/09/25 20:46:02 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_is_val_status(t_vrtx *vrtx, char *name_node)
{
	t_vrtx *ptr;

	ptr = ft_srch_vrtx(&vrtx, name_node);
	if (ptr->status >= 1)
		return (0);
	return (1);
}

int			ft_is_valid_step(t_vrtx *vrtx_ptr, t_adj *adj_ptr)
{
	if (vrtx_ptr->step < adj_ptr->lnk->step || adj_ptr->lnk->step == -1)
		return (1);
	return (0);
}

void		ft_b_gph3(t_adj *adj_ptr, t_vrtx *vrtx_ptr, t_q **q, int lvl)
{
	enqueue(adj_ptr->name, q, lvl + 1);
	if (adj_ptr->lnk->status == 0)
		adj_ptr->lnk->step = vrtx_ptr->step + 1;
	adj_ptr->lnk->status = 1;
}

int			ft_b_gph2(t_adj *adj_ptr, t_vrtx *vrtx_ptr, t_q **q, int lvl)
{
	enqueue(adj_ptr->name, q, lvl + 1);
	if (vrtx_ptr->status == 0)
		vrtx_ptr->step = lvl;
	return (1);
}

int			ft_by_gph(t_ls_rts **lst_rt, t_vrtx **vrtx, t_q **q, int lvl)
{
	t_vrtx	*vrtx_ptr;
	t_adj	*adj_ptr;

	if ((vrtx_ptr = ft_srch_vrtx(vrtx, (*q)->name)) && (*q)->status != 2)
		if (vrtx_ptr->status < 2)
		{
			adj_ptr = vrtx_ptr->adj;
			while (adj_ptr != NULL)
			{
				if (adj_ptr->lnk == NULL)
					if (ft_b_gph2(adj_ptr, vrtx_ptr, q, lvl))
						break ;
				if (ft_is_val_status((*vrtx), adj_ptr->name)
					&& ft_is_valid_step(vrtx_ptr, adj_ptr))
					ft_b_gph3(adj_ptr, vrtx_ptr, q, lvl);
				adj_ptr = adj_ptr->next;
			}
		}
	vrtx_ptr->status = 2;
	(*q)->status = 2;
	if (dequeue(q) == NULL)
		return (0);
	ft_by_gph(lst_rt, vrtx, q, lvl + 1);
	return (0);
}
