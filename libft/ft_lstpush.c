/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:35:40 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/07 14:35:46 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list *current, void *content, size_t content_size)
{
	size_t i;

	i = 0;
	while (current->next != NULL)
	{
		i++;
		current = current->next;
	}
	current->next = (t_list *)malloc(sizeof(t_list));
	current->next->content = content;
	current->next->content_size = content_size++;
	current->next->next = NULL;
}
