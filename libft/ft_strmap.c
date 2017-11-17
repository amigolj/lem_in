/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:12:36 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/01 21:30:47 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (*s)
	{
		*str = f(*s++);
		str++;
		i++;
	}
	*str = '\0';
	str -= i;
	return (str);
}
