/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:28:52 by mkurchin          #+#    #+#             */
/*   Updated: 2017/09/28 13:28:53 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_coord_farms(t_vrtx *ptr, char *line)
{
	char *coord;

	coord = ft_strchr(line, ' ');
	while (ptr != NULL)
	{
		if (!ft_strcmp(ptr->coord, coord))
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int		hndl_s_e_rm(t_vrtx **vrtx, t_st *ptr, t_fl *fl, char *line)
{
	char **arr;

	arr = ft_strsplit2(line, ' ');
	if (fl->rm_start == 0 && fl->cmd_start == 1)
	{
		fl->rm_start = 1;
		ptr->rm_start = ft_strdup(arr[0]);
	}
	else if (fl->rm_end == 0 && fl->cmd_end == 1)
	{
		fl->rm_end = 1;
		ptr->rm_end = ft_strdup(arr[0]);
	}
	ptr->cnt_rm++;
	if (check_coord_farms(*vrtx, line))
	{
		free_arr(arr);
		return (1);
	}
	ft_add_vrtx(vrtx, ptr, arr[0], line);
	free_arr(arr);
	return (0);
}

int		ft_is_cmd(char *line, t_st *ptr)
{
	if (*line == '#' && (*(line + 1)) == '#' && !ft_strcmp("start", line + 2))
		return (1);
	if (*line == '#' && (*(line + 1)) == '#' && !ft_strcmp("end", line + 2))
		return (2);
	if (*line == '#' && (*(line + 1)) == '#' &&
		!ft_strcmp("show routes", line + 2))
	{
		ptr->shw_routes = 1;
		return (3);
	}
	if (*line == '#' && (*(line + 1)) == '#' &&
		!ft_strcmp("show steps", line + 2))
	{
		ptr->shw_cnt_step = 1;
		return (4);
	}
	if (*line == '#' && (*(line + 1)) == '#')
		return (5);
	return (0);
}

int		is_valid_order(t_fl *fl, char *line, t_st *ptr)
{
	if (ft_is_cmd(line, ptr))
		return (1);
	if (fl->ant == 0 && !is_num_ant(line) && !ft_is_cmd(line, ptr))
		return (0);
	return (1);
}

int		save_ant(t_st *ptr, char *line, t_fl *fl)
{
	char *ant;

	ptr->cnt_ant = ft_atoi(line);
	ant = ft_itoa(ptr->cnt_ant);
	if ((ft_strcmp(line, ant)))
	{
		free(ant);
		return (1);
	}
	free(ant);
	fl->ant = 1;
	return (0);
}
