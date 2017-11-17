/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 13:41:21 by mkurchin          #+#    #+#             */
/*   Updated: 2017/06/30 13:41:34 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <limits.h>
# include <errno.h>
# include "src/libft.h"
# include "src/ft_printf.h"
# include "src/get_next_line.h"

typedef struct	s_map {

	char			*line;
	struct s_map	*next;

}				t_map;

typedef struct	s_adj {

	int				id;
	int				status;
	char			*name;
	struct s_vrtx	*lnk;
	struct s_adj	*next;

}				t_adj;

typedef struct	s_queue {

	int				id;
	char			*name;
	int				status;
	int				step;
	struct s_queue	*next;

}				t_q;

typedef struct	s_vrtx {

	int				id;
	int				status;
	int				step;
	char			*name;
	char			*coord;
	char			*line;
	struct s_adj	*adj;
	struct s_vrtx	*prev;
	struct s_vrtx	*next;

}				t_vrtx;

typedef struct	s_route {

	int				id;
	int				lem;
	char			*name;
	struct s_route	*prev;
	struct s_route	*next;

}				t_route;

typedef struct	s_lst_routes {

	int					id;
	int					len;
	struct s_route		*ptr_route;
	struct s_lst_routes	*prev;
	struct s_lst_routes	*next;

}				t_ls_rts;

typedef struct	s_st {

	int		color;
	int		shw_routes;
	int		shw_cnt_step;
	int		cnt_step;
	int		cnt_ant;
	int		pos_start;
	int		pos_end;
	int		cnt_line;
	int		cnt_rm;
	int		cnt_lnk;
	char	*rm_start;
	char	*rm_end;

}				t_st;

typedef struct	s_fl {

	int		ant;
	int		cmd_start;
	int		cmd_end;
	int		rm_end;
	int		rm_start;
	int		end_link;
	int		link;
	int		crt_lst_rm;

}				t_fl;

int				ft_add_vrtx(t_vrtx **vrtx, t_st *ptr, char *arr, char *line2);
void			ft_create_struct(t_st **ptr, t_fl **fl);
int				ft_hndl_cmd(t_st *ptr, t_fl *fl, char *line, char *word);
int				is_num_ant(char *line);
int				is_correct_str(t_vrtx *vrtx, char *line, t_fl *fl, t_st *ptr);
int				is_correct_str_lnk(char **line);
int				add_ln_data(t_vrtx **vrtx, t_st *ptr, char *line, t_map **map);
char			**ft_strsplit2(char const *s, char c);
void			*ft_srch_vrtx(t_vrtx **vrtx, char *line);
int				ft_add_route(t_ls_rts **vrtx);
int				ft_add_node_route(t_ls_rts **vrtx, t_q *q);
void			*ft_srch_q(char *line, t_q *q);
int				pop(t_q **q);
int				ft_sort_ways(t_ls_rts **lst_rt);
int				lst_len(t_q *q);
t_vrtx			**ft_sort_vrtx(t_vrtx **vrtx, t_st *ptr);
void			del_cross_rt(t_ls_rts **ptr, t_ls_rts **head);
int				ft_crs_node(t_ls_rts **rts, t_ls_rts **cur, t_ls_rts **cur2);
int				ft_del_dubl(t_ls_rts **lst_rt);
int				ft_start_end_rt(int ant_finish, t_st *ptr);
int				replace_lem(t_route *route, t_st *ptr, int *i, int *ant_finish);
int				hndl_remain_ant(t_route *route, t_st *ptr, int *ant_finish);
int				ft_in_ant(t_route *route, t_st *ptr, int *i, int *ant_finish);
void			simple_rplc_ant (t_route *route, t_st *ptr, int *ant_finish);
int				find_pst_queue_for_rplc_ant(t_route **route, t_st *ptr);
int				ft_parse_data(t_vrtx **vrtx, t_st *ptr, t_fl *fl, char *line);
int				enqueue(char *name, t_q **q, int lvl);
int				ft_by_gph(t_ls_rts **lst_rt, t_vrtx **vrtx, t_q **q, int lvl);
int				is_valid_order (t_fl *fl, char *line, t_st *ptr);
int				ft_is_cmd(char *line, t_st *ptr);
int				is_str_lnk(char *line);
int				free_arr(char **arr);
char			*ft_strsub2(char const *s, unsigned int start, size_t len);
t_q				*dequeue(t_q **q);
t_vrtx			*ft_srch_lnk(t_vrtx **vrtx, char *name_node);
size_t			ft_strlen2(const char *s);
void			ft_exit(void);
int				ft_count_elem(char **str);
void			free_mem(t_st *ptr, t_fl *fl, t_vrtx *vrtx);
void			free_route(t_route *rt);
int				ft_s_w2(t_ls_rts **lst_rt, t_st *ptr, t_q **q, t_adj *adj_ptr);
int				ft_select_ways(t_ls_rts **lst_rt, t_st *ptr);
void			ft_hndl_data(t_vrtx **vrtx, t_st *ptr);
void			free_q(t_q *q);
void			ft_out_ant(int ant_finish, t_ls_rts **lst_rt, t_st *ptr, int i);
int				check_coord_farms(t_vrtx *ptr, char *line);
int				save_ant(t_st *ptr, char *line, t_fl *fl);
int				hndl_s_e_rm(t_vrtx **vrtx, t_st *ptr, t_fl *fl, char *line);
int				is_correct_start_end_rm(t_st *ptr, t_fl *fl);
int				is_correct_rm_coord(char **str);
int				is_adj_st_end_rm(t_vrtx **vrtx, t_st *ptr);
void			free_lst_rt(t_ls_rts *lst_rt);
int				is_cnt_len_rt_cnt_ant(t_st *ptr, t_ls_rts *ls_rts);
int				how_route_eq_rt(t_ls_rts *head);
int				out_eq(t_st *ptr, t_ls_rts **lst_rt, int ant_finish, int i);
void			color_set(t_st *ptr);
void			display_map_l(t_st *ptr, t_vrtx *vrtx, t_map *map);
void			ft_parse_core(t_vrtx **vrtx, t_st *ptr, t_fl *fl, t_map **map);
int				add_ln_map(t_map **map, char *line);

#endif
