/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hndl_route2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:31:20 by mkurchin          #+#    #+#             */
/*   Updated: 2017/09/28 11:31:21 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lnk_rt(t_route *tmp2_lnk, t_ls_rts *ptr1, t_ls_rts *ptr2, int len)
{
	tmp2_lnk = ptr1->ptr_route;
	len = ptr1->len;
	ptr1->ptr_route = ptr2->ptr_route;
	ptr1->len = ptr2->len;
	ptr2->ptr_route = tmp2_lnk;
	ptr2->len = len;
}

int			ft_sort_ways(t_ls_rts **lst_rt)
{
	t_ls_rts	*head;
	t_ls_rts	*ptr1;
	t_ls_rts	*ptr2;
	t_route		*tmp2_lnk;
	int			len;

	ptr1 = (*lst_rt);
	ptr2 = ptr1->next;
	head = ptr1;
	tmp2_lnk = NULL;
	len = 0;
	while (ptr1 != NULL)
	{
		ptr2 = ptr1->next;
		while (ptr2 != NULL)
		{
			if (ptr1->len > ptr2->len)
				lnk_rt(tmp2_lnk, ptr1, ptr2, len);
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	while (head != NULL)
		head = head->next;
	return (0);
}

int			ft_add_route(t_ls_rts **p)
{
	static int	cnt = 0;
	t_ls_rts	*head;

	cnt++;
	if ((*p) == NULL)
	{
		(*p) = (t_ls_rts*)malloc(sizeof(t_ls_rts));
		(*p)->id = cnt;
		(*p)->len = 0;
		(*p)->ptr_route = NULL;
		(*p)->next = NULL;
		(*p)->prev = NULL;
		return (0);
	}
	head = *p;
	while (head->next != NULL)
		head = head->next;
	head->next = (t_ls_rts*)malloc(sizeof(t_ls_rts));
	head->next->id = cnt;
	head->next->len = 1;
	head->next->ptr_route = NULL;
	head->next->prev = head;
	head->next->next = NULL;
	return (0);
}

t_route		*ft_add_node_route2(t_ls_rts *cur, t_q *q, int i)
{
	t_route *ptr;

	cur->ptr_route = (t_route*)malloc(sizeof(t_route));
	ptr = cur->ptr_route;
	ptr->id = i;
	ptr->lem = 0;
	ptr->name = ft_strdup(q->name);
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}

int			ft_add_node_route(t_ls_rts **lst_rt, t_q *q)
{
	int			i;
	t_ls_rts	*cur;
	t_route		*ptr;

	i = 1;
	cur = *lst_rt;
	while (cur->next != NULL)
		cur = cur->next;
	ptr = ft_add_node_route2(cur, q, i);
	q = q->next;
	while (q != NULL)
	{
		ptr->next = (t_route*)malloc(sizeof(t_route));
		ptr->id = i;
		ptr->next->lem = 0;
		ptr->next->name = ft_strdup(q->name);
		ptr->next->next = NULL;
		ptr->next->prev = ptr;
		ptr = ptr->next;
		q = q->next;
		i++;
	}
	cur->len = i - 1;
	return (0);
}
