/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_cross_rt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 23:16:28 by mkurchin          #+#    #+#             */
/*   Updated: 2017/09/27 23:16:30 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_cross_rt(t_ls_rts **ptr, t_ls_rts **head)
{
	if ((*ptr)->id != (*head)->id)
	{
		if ((*head)->next == NULL)
		{
			free_route((*head)->ptr_route);
			free((*head));
			(*head)->prev->next = NULL;
			*head = NULL;
		}
		else if ((*head)->next != NULL)
		{
			(*head)->prev->next = (*head)->next;
			(*head)->next->prev = (*head)->prev;
			free_route((*head)->ptr_route);
			free((*head));
			*head = (*head)->next;
		}
	}
}

void	ft_del_cross_node2(t_ls_rts **head1, t_ls_rts **head2, t_ls_rts **rts)
{
	if ((*head1)->len <= (*head2)->len)
		del_cross_rt(rts, head2);
	else
		del_cross_rt(rts, head1);
}

int		ft_crs_node(t_ls_rts **rts, t_ls_rts **cur, t_ls_rts **cur2)
{
	t_route			*i;
	t_route			*j;
	t_ls_rts		**head1;
	t_ls_rts		**head2;

	i = (*cur)->ptr_route->next;
	head1 = cur;
	head2 = cur2;
	while (i != NULL)
	{
		j = (*cur2)->ptr_route->next;
		while (j != NULL)
		{
			if (!(ft_strcmp(i->name, j->name)) && i->next != NULL)
			{
				ft_del_cross_node2(head1, head2, rts);
				return (1);
			}
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int		ft_del_dubl(t_ls_rts **lst_rt)
{
	t_ls_rts *cur;
	t_ls_rts *cur2;

	cur = *lst_rt;
	cur2 = *lst_rt;
	while (cur->next != NULL)
	{
		cur2 = cur->next;
		while (cur2 != NULL)
		{
			if (!(ft_crs_node(lst_rt, &cur, &cur2)))
				cur2 = cur2->next;
		}
		cur = cur->next;
		if (cur == NULL)
			return (0);
	}
	return (0);
}

void	del_gnl(t_fd *ptr_lst, char *buffer)
{
	ft_strdel(&ptr_lst->temp);
	ft_strdel(&buffer);
}
