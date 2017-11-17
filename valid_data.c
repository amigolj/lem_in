/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:34:40 by mkurchin          #+#    #+#             */
/*   Updated: 2017/09/28 11:34:43 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_valid_coord(char **ptr, char *line)
{
	(*ptr)++;
	line = *ptr;
	*ptr = ft_strchr(line, ' ');
	if (*ptr == NULL)
		return (1);
	if (!ft_isdigit(*((*ptr) + 1)))
		return (0);
	return (1);
}

int		is_valid_room_lnk(t_vrtx *vrtx, char *line)
{
	char **str;

	str = ft_strsplit2(line, '-');
	if (!is_correct_str_lnk(str))
	{
		free_arr(str);
		return (0);
	}
	if (ft_srch_vrtx(&vrtx, str[0]) && ft_srch_vrtx(&vrtx, str[1]))
	{
		free_arr(str);
		return (1);
	}
	else
	{
		free_arr(str);
		perror("Not found vertex in str links:");
		exit(0);
	}
}

int		check_valid_coord2(char *ptr, char *line, char **str)
{
	if (check_valid_coord(&ptr, line))
		if (check_valid_coord(&ptr, line))
		{
			if (is_correct_rm_coord(str))
			{
				free_arr(str);
				return (1);
			}
		}
		else
		{
			free_arr(str);
			return (0);
		}
	else
	{
		free_arr(str);
		return (0);
	}
	return (0);
}

int		is_valid_room(char *line)
{
	char	*ptr;
	char	**str;

	ptr = ft_strchr(line, ' ');
	str = ft_strsplit2(line, ' ');
	if (ft_count_elem(str) != 3)
		if (free_arr(str))
			return (0);
	if (ptr == NULL)
		if (free_arr(str))
			return (0);
	if (!ft_isdigit(*(ptr + 1)))
	{
		free_arr(str);
		return (0);
	}
	else
	{
		if (check_valid_coord2(ptr, line, str))
			return (1);
		else
			return (0);
	}
}

int		is_correct_str(t_vrtx *vrtx, char *line, t_fl *fl, t_st *ptr)
{
	int		room;
	int		room_lnk;

	if (ft_is_cmd(line, ptr) || (is_num_ant(line) && fl->ant == 0) ||
		(*line == '#' && (*(line + 1)) != '#'))
		return (1);
	if (*line == '#' || fl->ant == 0)
		return (0);
	room = is_valid_room(line);
	room_lnk = is_valid_room_lnk(vrtx, line);
	if (room == 0 && room_lnk == 0)
		ft_exit();
	else if (room == 1)
		return (1);
	else if (room_lnk == 1)
	{
		if (ptr->rm_end != NULL && ptr->rm_start != NULL)
			return (2);
		ft_exit();
	}
	return (0);
}
