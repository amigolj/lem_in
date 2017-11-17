/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hndl_route.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:48:05 by mkurchin          #+#    #+#             */
/*   Updated: 2017/08/19 14:48:06 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_to_end(t_vrtx **cur)
{
	while ((*cur)->next != NULL)
		(*cur) = (*cur)->next;
}

void		ft_rplc_end(t_vrtx **vrtx, t_st *ptr)
{
	t_vrtx *head;
	t_vrtx *cur;
	t_vrtx *end;

	head = *vrtx;
	cur = *vrtx;
	end = (t_vrtx*)ft_srch_vrtx(vrtx, ptr->rm_end);
	if (head == end)
	{
		*vrtx = head->next;
		cur = head->next;
		ft_to_end(&cur);
		cur->next = end;
		end->prev = cur;
		end->next = NULL;
	}
	else if (end->next != NULL)
	{
		end->prev->next = end->next;
		ft_to_end(&cur);
		cur->next = end;
		end->prev = cur;
		end->next = NULL;
	}
}

void		ft_rplc_start2(t_vrtx **vrtx, t_vrtx *start)
{
	(*vrtx)->prev = start;
	start->prev->next = NULL;
	start->prev = NULL;
	start->next = *vrtx;
}

t_vrtx		*ft_rplc_start(t_vrtx **vrtx, t_st *ptr)
{
	t_vrtx *start;
	t_vrtx *cur;
	t_vrtx *end;

	cur = *vrtx;
	start = (t_vrtx*)ft_srch_vrtx(vrtx, ptr->rm_start);
	while (cur != NULL)
	{
		end = cur;
		cur = cur->next;
	}
	if (start == end)
		ft_rplc_start2(vrtx, start);
	else if (start->next != NULL)
	{
		start->prev->next = start->next;
		(*vrtx)->prev = start;
		(*vrtx)->prev->next = *vrtx;
		(*vrtx)->prev->prev = NULL;
	}
	return ((*vrtx)->prev);
}

t_vrtx		**ft_sort_vrtx(t_vrtx **vrtx, t_st *ptr)
{
	if (ft_strcmp((*vrtx)->name, ptr->rm_start))
		*vrtx = ft_rplc_start(vrtx, ptr);
	ft_rplc_end(vrtx, ptr);
	return (vrtx);
}
