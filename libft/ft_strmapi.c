/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:48:03 by tpacaly           #+#    #+#             */
/*   Updated: 2016/11/08 00:42:28 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*chaine;
	size_t	a;

	if (s == NULL)
		return (NULL);
	if ((chaine = ft_strdup((const char *)s)) == NULL)
		return (NULL);
	a = 0;
	while (chaine[a])
	{
		chaine[a] = f((unsigned int)a, chaine[a]);
		a++;
	}
	return (chaine);
}
