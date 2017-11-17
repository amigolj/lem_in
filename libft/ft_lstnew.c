/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 23:00:12 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/05 23:00:14 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	if (!content)
	{
		head->content = NULL;
		head->content_size = 0;
		return (head);
	}
	head->content = (void *)malloc(sizeof(content_size));
	if (!head->content)
		return (NULL);
	head->content = ft_memcpy(head->content, content, content_size);
	if (!content_size)
		head->content_size = 0;
	head->content_size = content_size;
	head->next = NULL;
	return (head);
}
