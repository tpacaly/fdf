/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affiche.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 03:09:21 by tpacaly           #+#    #+#             */
/*   Updated: 2017/06/06 16:19:32 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_affiche(char *fft, ...)
{
	va_list	liste;
	char	*s;

	va_start(liste, fft);
	while (*fft)
	{
		if (*fft == '%')
		{
			fft++;
			if (*fft == 's')
			{
				s = va_arg(liste, char *);
				write(1, s, ft_strlen(s));
			}
			if (*fft == 'd')
				ft_putnbr(va_arg(liste, int));
			fft++;
		}
		else
		{
			write(1, fft, 1);
			fft++;
		}
	}
	return (0);
}
