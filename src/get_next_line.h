/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 22:21:34 by mkurchin          #+#    #+#             */
/*   Updated: 2017/01/27 22:21:35 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 1

typedef struct	s_fd {

	int			fd;
	char		*temp;
	struct s_fd *next;

}				t_fd;

int				get_next_line(const int fd, char **line);
void			del_gnl(t_fd *ptr_lst, char *buffer);

#endif
