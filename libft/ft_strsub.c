/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:30:47 by tpacaly           #+#    #+#             */
/*   Updated: 2016/11/08 02:36:59 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			n;

	if (!s)
		return (NULL);
	n = 0;
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	while (n < len)
	{
		str[n] = s[start + n];
		n++;
	}
	str[n] = 0;
	return (str);
}
