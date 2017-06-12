/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 23:47:53 by tpacaly           #+#    #+#             */
/*   Updated: 2016/11/06 22:47:50 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*x;
	int				i;
	unsigned int	l;

	l = len;
	i = 0;
	x = b;
	while (l-- != 0)
		x[l] = c;
	return (b);
}
