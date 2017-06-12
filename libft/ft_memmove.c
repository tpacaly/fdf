/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 00:11:05 by tpacaly           #+#    #+#             */
/*   Updated: 2016/11/04 07:29:15 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*string1;
	const unsigned char	*string2;
	int					u;

	string1 = dst;
	string2 = src;
	u = len;
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
		while (--u >= 0)
			string1[u] = string2[u];
	return (dst);
}
