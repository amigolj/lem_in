/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 20:32:28 by mkurchin          #+#    #+#             */
/*   Updated: 2017/09/25 20:32:29 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_parse_data2(t_st *ptr, t_vrtx **vrtx, char *line)
{
	char **arr;

	ptr->cnt_rm++;
	arr = ft_strsplit2(line, ' ');
	if (check_coord_farms(*vrtx, line))
	{
		free_arr(arr);
		return (1);
	}
	ft_add_vrtx(vrtx, ptr, arr[0], line);
	free_arr(arr);
	return (0);
}

int		ft_parse_data3(t_fl *fl, t_st *ptr, char *line)
{
	if (*line == '#' && (*(line + 1)) != '#')
		return (0);
	else if (!is_valid_order(fl, line, ptr))
		return (0);
	return (1);
}

int		save_ant3(t_st *ptr, t_fl *fl, char *line)
{
	if (is_num_ant(line))
		if (save_ant(ptr, line, fl))
			return (1);
	return (0);
}

int		parse_data3(char *line, t_st *ptr, t_vrtx **vrtx)
{
	if (*line != '#' && *(line + 1) != '#' && !is_str_lnk(line))
		if (ft_parse_data2(ptr, vrtx, line))
			return (1);
	return (0);
}

int		ft_parse_data(t_vrtx **vrtx, t_st *ptr, t_fl *fl, char *line)
{
	if (ft_is_cmd(line, ptr) && fl->ant == 0)
		return (1);
	if (!ft_parse_data3(fl, ptr, line))
		return (0);
	if (fl->ant == 0)
		return (save_ant3(ptr, fl, line)) ? 1 : 0;
	if (!is_correct_str(*vrtx, line, fl, ptr))
		return (0);
	else if (fl->ant == 1)
	{
		if (fl->cmd_start == 0 && ft_is_cmd(line, ptr) == 1)
			ft_hndl_cmd(ptr, fl, line, "start");
		else if (fl->cmd_end == 0 && ft_is_cmd(line, ptr) == 2)
			ft_hndl_cmd(ptr, fl, line, "end");
		else if (fl->cmd_end == 0 && ft_is_cmd(line, ptr) == 5)
			return (0);
		else if (is_correct_start_end_rm(ptr, fl))
		{
			if (ft_is_cmd(line, ptr))
				return (0);
			return (hndl_s_e_rm(vrtx, ptr, fl, line)) ? 1 : 0;
		}
		return (parse_data3(line, ptr, vrtx)) ? 1 : 0;
	}
	return (0);
}
