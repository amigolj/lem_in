/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hndl_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 10:54:46 by mkurchin          #+#    #+#             */
/*   Updated: 2017/07/01 10:54:48 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_hndl_cmd(t_st *ptr, t_fl *fl, char *line, char *word)
{
	line += 2;
	if (!ft_strcmp(line, word))
	{
		if (!ft_strcmp("start", word))
		{
			fl->cmd_start = 1;
			ptr->pos_start = ptr->cnt_line;
		}
		if (!ft_strcmp("end", word))
		{
			fl->cmd_end = 1;
			ptr->pos_end = ptr->cnt_line;
		}
		return (1);
	}
	return (0);
}

int			is_num_ant(char *line)
{
	while (*line != '\0')
	{
		if (!ft_isdigit(*line))
			return (0);
		line++;
	}
	return (1);
}

t_vrtx		*ft_srch_lnk(t_vrtx **vrtx, char *name_node)
{
	t_vrtx *ptr;

	ptr = *vrtx;
	if (ptr->next == NULL)
		if (!ft_strcmp(ptr->name, name_node))
			return (ptr);
	while (ptr->next != NULL)
	{
		if (!ft_strcmp(ptr->name, name_node))
			return (ptr);
		ptr = ptr->next;
	}
	if (!ft_strcmp(ptr->name, name_node))
		return (ptr);
	return (0);
}
