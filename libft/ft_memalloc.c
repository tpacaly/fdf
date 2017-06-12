/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:59:54 by tpacaly           #+#    #+#             */
/*   Updated: 2016/11/06 22:45:33 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*chaine;
	void			*s;
	size_t			f;

	f = 0;
	chaine = (unsigned char*)malloc(sizeof(unsigned char) * size);
	s = (void *)chaine;
	if (chaine == '\0')
		return (chaine);
	while (f != size)
	{
		chaine[f] = '\0';
		f++;
	}
	return (s);
}
