/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:46:20 by tpacaly           #+#    #+#             */
/*   Updated: 2016/11/08 01:58:31 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*cur;
	char	*reader;
	size_t	len;

	cur = (char *)ft_memchr(dst, '\0', size);
	if (cur == NULL)
		return (size + ft_strlen(src));
	reader = (char *)src;
	len = (size_t)(cur - dst) + ft_strlen(reader);
	while ((size_t)(cur - dst) < size - 1 && *reader != '\0')
	{
		*cur = *reader;
		cur++;
		reader++;
	}
	*cur = '\0';
	return (len);
}
