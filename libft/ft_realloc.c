/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 19:26:57 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/13 19:26:59 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

void		*ft_realloc(void *ptr, size_t len, size_t num)
{
	void	*ptr2;

	if (!ptr)
		return (NULL);
	ptr2 = malloc(sizeof(char) * num + len);
	if (!ptr2)
		return (0);
	memmove(ptr2, ptr, len);
	free(ptr);
	return (ptr2);
}
