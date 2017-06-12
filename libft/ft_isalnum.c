/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:47:10 by tpacaly           #+#    #+#             */
/*   Updated: 2016/11/07 22:47:17 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if (0x40 < c && c < 0x5b)
		return (1);
	if (0x60 < c && c < 0x7b)
		return (1);
	if (0x2f < c && c < 0x3a)
		return (1);
	return (0);
}
