/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hndl_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 23:55:20 by mkurchin          #+#    #+#             */
/*   Updated: 2017/09/27 23:55:22 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_add_adj(t_vrtx **vrtx, t_vrtx **cur, t_st *ptr, char *line)
{
	t_adj *head;

	if ((*cur)->adj == NULL)
	{
		(*cur)->adj = (t_adj*)malloc(sizeof(t_adj));
		(*cur)->adj->id = ptr->cnt_line;
		(*cur)->adj->name = strdup(line);
		(*cur)->adj->lnk = ft_srch_lnk(vrtx, (*cur)->adj->name);
		if (!(*cur)->adj->lnk)
		{
			perror("I can't find this link\n");
			exit(0);
		}
		(*cur)->adj->next = NULL;
		return (0);
	}
	head = (*cur)->adj;
	while (head->next != NULL)
		head = head->next;
	head->next = (t_adj*)malloc(sizeof(t_adj));
	head->next->id = ptr->cnt_line;
	head->next->name = ft_strdup(line);
	head->next->lnk = ft_srch_lnk(vrtx, line);
	head->next->next = NULL;
	return (0);
}

int			pop(t_q **q)
{
	t_q *head;

	if ((*q) == NULL)
		return (1);
	head = *q;
	if (head->next == NULL)
	{
		free(head->name);
		free(head);
		head = NULL;
		return (0);
	}
	while (head->next->next != NULL)
		head = head->next;
	free(head->next->name);
	free(head->next);
	head->next = NULL;
	return (0);
}

void		*ft_srch_vrtx(t_vrtx **vrtx, char *line)
{
	t_vrtx	*cur;

	cur = *vrtx;
	while (cur != NULL)
	{
		if (!strcmp(cur->name, line))
			return (cur);
		cur = cur->next;
	}
	return (0);
}

int			add_ln_data(t_vrtx **vrtx, t_st *ptr, char *line, t_map **map)
{
	char	**arr;
	t_vrtx	*cur;
	t_vrtx	*cur2;

	arr = ft_strsplit2(line, '-');
	if ((cur = ft_srch_vrtx(vrtx, arr[0])))
	{
		add_ln_map(map, line);
		ft_add_adj(vrtx, &cur, ptr, arr[1]);
		if (!(cur2 = ft_srch_vrtx(vrtx, arr[1])))
		{
			ft_add_vrtx(vrtx, ptr, arr[1], line);
			ft_add_adj(vrtx, &cur2, ptr, arr[0]);
		}
		else
			ft_add_adj(vrtx, &cur2, ptr, arr[0]);
	}
	else
	{
		free_arr(arr);
		ft_printf("Error: not found vrtx\n");
		exit(0);
	}
	free_arr(arr);
	return (1);
}
