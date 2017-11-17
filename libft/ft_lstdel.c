/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:29:29 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/06 19:29:31 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *elem;
	t_list *current;

	if (alst != NULL)
	{
		elem = *alst;
		while (elem != NULL)
		{
			current = elem;
			ft_lstdelone(&elem, (*del));
			elem = current->next;
		}
		*alst = NULL;
	}
}
