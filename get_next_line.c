/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 22:22:09 by mkurchin          #+#    #+#             */
/*   Updated: 2017/01/27 22:22:11 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char			*ft_strrjoin(char *s1, char const *s2)
{
	char	*s3;
	int		i;
	size_t	len;

	len = ft_strlen2(s1) + ft_strlen2((char*)s2);
	if (!(s3 = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
			*s3++ = s1[i++];
		free(s1);
		s1 = NULL;
	}
	if (s2)
	{
		while (*s2)
		{
			*s3++ = *s2++;
			i++;
		}
	}
	*s3 = '\0';
	return (s3 -= i);
}

static int		ft_create_node(t_fd **node, int fd)
{
	if (!(*node = (t_fd *)malloc(sizeof(t_fd))))
		return (0);
	(*node)->fd = fd;
	(*node)->next = NULL;
	(*node)->temp = NULL;
	return (1);
}

static	t_fd	*ft_search_lst_fd(t_fd **head, int fd)
{
	t_fd	*ptr_head;
	t_fd	*current;

	ptr_head = *head;
	if (*head == NULL)
		ft_create_node(head, fd);
	else
	{
		current = *head;
		while (current != NULL)
		{
			if (current->fd == fd)
				return (current);
			current = current->next;
		}
		if (!(ft_create_node(&current, fd)))
			return (0);
		while (ptr_head->next != NULL)
			ptr_head = ptr_head->next;
		ptr_head->next = current;
		return (current);
	}
	return (*head);
}

static int		ft_handle_temp(t_fd *ptr_lst, char **line, char **buffer)
{
	char *tmp;
	char *ptr;

	if (ft_strchr(ptr_lst->temp, '\n'))
	{
		ptr = ft_strchr(ptr_lst->temp, '\n');
		*ptr = '\0';
		*line = ft_strdup(ptr_lst->temp);
		tmp = ft_strdup(ptr + 1);
		ft_strdel(&ptr_lst->temp);
		ptr_lst->temp = ft_strdup(tmp);
		ptr = NULL;
		ft_strdel(&tmp);
		ft_strdel(buffer);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char		*buffer;
	int			readfd;
	t_fd		*ptr_lst;
	static t_fd	*head;

	buffer = ft_strnew(BUFF_SIZE);
	if ((readfd = read(fd, buffer, 0)) == -1 || !BUFF_SIZE || !line)
		return (-1);
	ptr_lst = ft_search_lst_fd(&head, fd);
	while ((readfd = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[readfd] = '\0';
		ptr_lst->temp = ft_strrjoin(ptr_lst->temp, buffer);
		if (ft_handle_temp(ptr_lst, line, &buffer))
			return (1);
	}
	if (ptr_lst->temp != NULL && *(ptr_lst)->temp != 0)
	{
		if (ft_handle_temp(ptr_lst, line, &buffer))
			return (1);
		*line = ft_strdup(ptr_lst->temp);
		del_gnl(ptr_lst, buffer);
		return (1);
	}
	return (0);
}
