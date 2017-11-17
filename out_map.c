/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 02:05:00 by mkurchin          #+#    #+#             */
/*   Updated: 2017/09/29 02:05:01 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_parse_core(t_vrtx **vrtx, t_st *ptr, t_fl *fl, t_map **map)
{
	int		err;
	char	*line;

	line = NULL;
	while ((err = get_next_line(0, &line)) && line != '\0')
	{
		if (err == -1)
			ft_exit();
		if (ft_parse_data(vrtx, ptr, fl, line))
			ft_exit();
		if (is_str_lnk(line))
			add_ln_data(vrtx, ptr, line, map);
		ptr->cnt_line++;
		free(line);
	}
	if (line != NULL)
		free(line);
	else
		ft_exit();
}

void	display_map_l(t_st *ptr, t_vrtx *vrtx, t_map *map)
{
	ft_printf("%i\n", ptr->cnt_ant);
	while (vrtx != NULL)
	{
		ft_printf("%s\n", vrtx->line);
		vrtx = vrtx->next;
	}
	while (map != NULL)
	{
		ft_printf("%s\n", map->line);
		map = map->next;
	}
}
