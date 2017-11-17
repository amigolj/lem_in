/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 20:40:20 by mkurchin          #+#    #+#             */
/*   Updated: 2017/09/25 20:40:21 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_add_vrtx2(t_vrtx **vrtx, t_st *ptr, char *arr, char *line)
{
	(*vrtx) = (t_vrtx*)malloc(sizeof(t_vrtx));
	(*vrtx)->id = ptr->cnt_rm;
	(*vrtx)->status = 0;
	(*vrtx)->step = -1;
	(*vrtx)->name = strdup(arr);
	(*vrtx)->coord = strdup(ft_strchr(line, ' '));
	(*vrtx)->line = strdup(line);
	(*vrtx)->adj = NULL;
	(*vrtx)->prev = NULL;
	(*vrtx)->next = NULL;
}

int		ft_add_vrtx(t_vrtx **vrtx, t_st *ptr, char *arr, char *line)
{
	t_vrtx *head;

	if ((*vrtx) == NULL)
	{
		ft_add_vrtx2(vrtx, ptr, arr, line);
		return (0);
	}
	head = *vrtx;
	while (head->next != NULL)
		head = head->next;
	head->next = (t_vrtx*)malloc(sizeof(t_vrtx));
	head->next->id = ptr->cnt_rm;
	head->next->status = 0;
	head->next->step = -1;
	head->next->name = ft_strdup(arr);
	head->next->coord = ft_strdup(ft_strchr(line, ' '));
	head->next->line = ft_strdup(line);
	head->next->adj = NULL;
	head->next->prev = head;
	head->next->next = NULL;
	return (0);
}

t_q		*dequeue(t_q **q)
{
	t_q *next_node;

	if (*q == NULL)
		return (NULL);
	next_node = (*q)->next;
	free((*q)->name);
	free(*q);
	(*q) = next_node;
	return ((*q));
}

int		enqueue(char *name, t_q **q, int lvl)
{
	t_q *head;

	if ((*q) == NULL)
	{
		(*q) = (t_q*)malloc(sizeof(t_q));
		(*q)->name = strdup(name);
		(*q)->step = lvl;
		(*q)->status = 0;
		(*q)->next = NULL;
		return (0);
	}
	head = *q;
	while (head->next != NULL)
		head = head->next;
	head->next = (t_q*)malloc(sizeof(t_q));
	head->next->name = ft_strdup(name);
	head->next->step = lvl;
	head->next->status = 0;
	head->next->next = NULL;
	return (0);
}
