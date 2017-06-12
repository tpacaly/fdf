/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 06:34:54 by tpacaly           #+#    #+#             */
/*   Updated: 2016/11/06 22:44:45 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char	*chaine1;
	unsigned char	*chaine2;

	if (n == 0 || s1 == s2)
		return (s1);
	chaine1 = (unsigned char *)s1;
	chaine2 = (unsigned char *)s2;
	while (--n)
		*chaine1++ = *chaine2++;
	*chaine1 = *chaine2;
	return (s1);
}
