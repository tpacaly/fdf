/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:42:59 by tpacaly           #+#    #+#             */
/*   Updated: 2016/11/08 03:15:56 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char			*ft_strtrim(char const *s)
{
	char		*start;
	size_t		len;

	if (s == NULL)
		return (NULL);
	start = (char *)s;
	while (ft_is_whitespace(*start) == 1)
		start++;
	if (*start == '\0')
		return (ft_strnew(0));
	len = ft_strlen(start);
	while (ft_is_whitespace(start[len - 1]) == 1)
		len--;
	return (ft_strsub(start, 0, len));
}
