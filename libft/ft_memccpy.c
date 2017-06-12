/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:35:02 by tpacaly           #+#    #+#             */
/*   Updated: 2016/11/07 23:05:59 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*s1;
	char		*s2;
	size_t		u;

	u = 0;
	s1 = (char *)dst;
	s2 = (char *)src;
	while (u < n)
	{
		s1[u] = (unsigned char)s2[u];
		if (s2[u] == c)
			return (s1 + u + 1);
		u++;
	}
	return (NULL);
}
