/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:38:37 by tpacaly           #+#    #+#             */
/*   Updated: 2016/11/08 02:37:38 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	taille;
	char	*chaine;

	if (!s1 || !s2)
		return (NULL);
	taille = ft_strlen(s1) + ft_strlen(s2);
	chaine = (char *)malloc(sizeof(*chaine) * (taille + 1));
	if (chaine == NULL)
		return (NULL);
	ft_strcpy(chaine, s1);
	ft_strcat(chaine, s2);
	return (chaine);
}
