/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 21:08:49 by mkurchin          #+#    #+#             */
/*   Updated: 2017/04/18 21:08:50 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <inttypes.h>
# include <limits.h>

# define MASK1 128
# define MASK2 192
# define MASK3 224
# define MASK4 240

char			*g_spec_form[6];

typedef struct	s_var {

	int		flag;
	int		width;
	int		precision;
	int		length;
	int		type;
	int		space;
	int		zero;
	int		diez;
	int		plus;
	int		sign;
	int		dote;
}				t_var;

int				ft_handle_fl_num_u(void *var, t_var *ptr);
int				ft_printf(const char *format, ...);
void			ft_add_fl(char *fl, int *p, t_var *ptr);
intmax_t		ft_cast_long(void *arg, t_var *p);
void			ft_bzero(void *s, size_t n);
int				ft_handle_fl_str(void *arg, t_var *ptr);
int				ft_handle_fl_num(void *arg, t_var *ptr);
int				ft_handl_wdth_num(t_var *ptr, int len, char chr);
int				ft_handl_sign_u(t_var *ptr, uintmax_t num);
char			*ft_itoa_base(uintmax_t arg, int base, t_var *ptr);
int				ft_is_sign(t_var *p, intmax_t arg);
int				ft_handl_sign_u(t_var *p, uintmax_t n);
int				ft_handl_sign(t_var *p, intmax_t num);
int				ft_handl_precis_num(t_var *ptr, int len);
int				ft_hndl_msk(wchar_t *str);
int				ft_parse(char *format, t_var *ptr);
int				ft_print_mod(const char *format, t_var *ptr, void *arg);
void			ft_print_utf8(int *c);
int				ft_putstr2(const char **s);
int				ft_putstr_n(void *s, int len, t_var *ptr);
int				ft_count_utf8(wchar_t *str);
int				ft_sv_fl(char *fl, int i, t_var *ptr);
size_t			ft_strlen_wchr(void *arg, t_var *ptr);
int				ft_srch_dot(char *str);
int				ft_wht_byte(wchar_t *arg, int len);
void			ft_bzero(void *memptr, size_t num);
int				ft_isdigit(int c);
void			ft_putstr(char const *s);
int				ft_atoi(const char *str);
size_t			ft_strlen(char *s);
int				ft_srch(const char *format, t_var *ptr);
int				ft_print_wchar(void *str);
int				ft_valid_byte(wchar_t *str, int len);
int				ft_is_base(t_var *ptr);
int				ft_cnt_byte_chr(wchar_t *str);
int				ft_cnt_byte_chr2(wchar_t chr);
int				ft_hndl_str_len(int cn_dig, t_var *p);
int				cs_diez(t_var *p, intmax_t n, int cn_dig, int b);
int				cs_space(t_var *p, intmax_t n, int cn_dig, int b);
int				cs_zero(t_var *p, intmax_t n, int cn_dig, int b);
int				cs_plus(t_var *p, intmax_t n, int cn_dig, int b);
int				cs_minus(t_var *p, intmax_t n, int cn_dig, int b);
intmax_t		ft_is_min_d(intmax_t n, t_var *p);
int				cs_null(t_var *p, intmax_t n, int cn_dig, int b);
int				ft_cnt_digit(intmax_t n, int b, t_var *p);
int				cs_null_u(t_var *p, uintmax_t n, int cn_dig, int b);
int				cs_space_u(t_var *p, uintmax_t n, int cn_dig, int b);
int				cs_zero_u(t_var *p, uintmax_t n, int cn_dig, int b);
int				cs_plus_u(t_var *p, uintmax_t n, int cn_dig, int b);
int				cs_minus_u(t_var *p, uintmax_t n, int cn_dig, int b);
int				cs_diez_u(t_var *p, uintmax_t n, int cn_dig, int b);
int				ft_cnt_digit_u(uintmax_t n, int b, t_var *p);
int				ft_isunsn_t(t_var *p);
int				ft_conv_2b(unsigned char *ptr, int *arr);
int				ft_conv_3b(unsigned char *ptr, int *arr);
int				ft_wht_byte(wchar_t *str, int len);
int				ft_handl_precis_str(t_var *ptr, void *arg, int len);
int				ft_handl_wdth_str(t_var *ptr, int len, char chr);
int				hndl_null_s(void *arg, t_var *p, int l_chr);
int				hndl_min_s(void *arg, t_var *p, int l_chr, int len_byte);
void			hndl_zero_s(void *arg, t_var *p, int l_chr, int len_byte);
int				ft_putstr3(const char **s, t_var *ptr);
void			ft_fill_zero(t_var *ptr);
int				ft_is_null_ptr(t_var *ptr);

#endif
