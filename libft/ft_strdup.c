/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:08:36 by tpacaly           #+#    #+#             */
/*   Updated: 2016/11/07 23:12:12 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*chaine;
	int		taille;
	int		i;

	i = 0;
	taille = 0;
	while (s1[taille])
		taille++;
	if ((chaine = (char*)malloc(sizeof(*chaine) * (taille + 1))) == NULL)
		return (NULL);
	while (i < taille)
	{
		chaine[i] = s1[i];
		i++;
	}
	chaine[taille] = '\0';
	return (chaine);
}
