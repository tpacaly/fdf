/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:44:24 by tpacaly           #+#    #+#             */
/*   Updated: 2016/11/07 22:10:00 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*cf;
	char	*chaine;

	i = 0;
	cf = 0;
	chaine = (char*)s;
	while (s[i])
	{
		if (s[i] == c)
		{
			cf = (char*)&s[i];
			i++;
		}
		else
			i++;
	}
	if (s[i] == c)
		cf = (char*)&s[i];
	return (cf);
}
