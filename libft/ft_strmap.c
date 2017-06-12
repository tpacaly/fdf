/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:53:13 by tpacaly           #+#    #+#             */
/*   Updated: 2016/11/08 00:40:08 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*chaine;
	size_t	a;

	if (s == NULL)
		return (NULL);
	if ((chaine = ft_strdup(s)) == NULL)
		return (NULL);
	a = 0;
	while (chaine[a])
	{
		chaine[a] = f(chaine[a]);
		a++;
	}
	return (chaine);
}
