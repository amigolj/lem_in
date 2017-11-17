/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 22:07:58 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/06 22:07:59 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*elem_lst;
	t_list	*new_lst;

	if (lst == NULL)
		return (NULL);
	tmp = f(lst);
	new_lst = ft_lstnew(tmp->content, tmp->content_size);
	if (new_lst == NULL)
		return (NULL);
	elem_lst = new_lst;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		elem_lst->next = ft_lstnew(tmp->content, tmp->content_size);
		if (elem_lst->next == NULL)
			return (NULL);
		elem_lst = elem_lst->next;
		lst = lst->next;
	}
	return (new_lst);
}
