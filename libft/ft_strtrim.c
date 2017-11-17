/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <mkurchin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:42:59 by mkurchin          #+#    #+#             */
/*   Updated: 2016/12/02 11:59:14 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_start_pos(char const *s)
{
	char	*str;

	while (*s)
	{
		if (*s == 9 || *s == 10 || *s == 32)
			s++;
		else
			break ;
	}
	return (str = (char *)s);
}

static char		*ft_fin_pos(char const *s)
{
	char	*str;
	int		len;

	len = ft_strlen((char *)s);
	str = (char *)&s[len];
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\0')
		str--;
	return (str);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*str_start;
	char	*str_fin;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	str_start = ft_start_pos(s);
	str_fin = ft_fin_pos(s);
	while (str_start <= str_fin)
	{
		str_start++;
		i++;
	}
	str_start -= i;
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (str_start <= str_fin)
		*str++ = *str_start++;
	*str = '\0';
	return (str -= i);
}
