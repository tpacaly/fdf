/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 21:33:46 by tpacaly           #+#    #+#             */
/*   Updated: 2016/11/08 00:13:15 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*chaine;
	int		v;
	short	cmpteur;
	char	is_neg;

	if ((is_neg = 1) && n == -2147483648)
		return (ft_strdup("-2147483648"));
	n < 0 ? n = -n : is_neg--;
	if (!(cmpteur = 0) && n == 0)
		return (ft_strdup("0"));
	v = n;
	while ((n /= 0xa) > 0)
		cmpteur++;
	if ((chaine = ft_memalloc(cmpteur + 2 + is_neg)) == NULL)
		return (NULL);
	chaine[cmpteur + 2 + is_neg] = 0;
	if (is_neg == 1)
		chaine[0] = '-';
	cmpteur += is_neg;
	while (v > 0)
	{
		chaine[cmpteur--] = (v % 0xa) + '0';
		v /= 0xa;
	}
	return (chaine);
}
