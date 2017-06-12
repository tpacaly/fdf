/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 02:53:43 by tpacaly           #+#    #+#             */
/*   Updated: 2017/06/09 03:19:55 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*chainefraiche(char **s, char *buffer, size_t n)
{
	size_t	n0;
	char	*ret;

	if (!*s)
		n0 = 0;
	else
		n0 = ft_strlen(*s);
	if (!(ret = ft_strnew(n0 + n)))
		return (0);
	if (*s)
		ft_strcpy(ret, *s);
	ft_strncat(ret, buffer, n);
	free(*s);
	return (ret);
}

int			videcache(t_sttc **cache, int fd)
{
	free(cache[fd]->s);
	cache[fd]->s = 0;
	cache[fd]->s0 = 0;
	return (1);
}

t_sttc		*lyre(t_sttc **statique, int fd)
{
	long long	t;
	char		c[BUFF_SIZE + 1];

	if (!statique[fd])
	{
		if (!(statique[fd] = (t_sttc*)malloc(sizeof(t_sttc))))
			return (0);
		statique[fd]->m = 0;
	}
	statique[fd]->s = 0;
	while ((t = read(fd, c, BUFF_SIZE)))
	{
		if (t == -1)
			return (0);
		if (!(statique[fd]->s = chainefraiche(&statique[fd]->s, c, t)))
			return (0);
		statique[fd]->m = t;
		if (ft_strchr(statique[fd]->s, 10))
			break ;
	}
	statique[fd]->a = (statique[fd]->s) ? 1 : 0;
	statique[fd]->a0 = (t && t == statique[fd]->m) ? 1 : 0;
	statique[fd]->m = t;
	statique[fd]->s0 = statique[fd]->s;
	return (statique[fd]);
}

int			get_next_line(const int fd, char **line)
{
	static t_sttc	*bff[MAX_FD];
	char			*nl;

	if (!line || fd < 0 || fd >= MAX_FD || !(*line = ft_strnew(0)))
		return (-1);
	while (1)
	{
		if ((!bff[fd] || !bff[fd]->a) && !lyre(bff, fd))
			return (-1);
		if (!bff[fd]->a && !bff[fd]->a0 && videcache(bff, fd))
			return ((**line) ? 1 : 0);
		if ((nl = ft_strchr(bff[fd]->s0, 10)))
		{
			if (!(*line = chainefraiche(line, bff[fd]->s0, nl - bff[fd]->s0)))
				return (-1);
			if (!*(bff[fd]->s0 = nl + 1))
				bff[fd]->a = 0;
			return (1);
		}
		if (!(*line = chainefraiche(line, bff[fd]->s0, ft_strlen(bff[fd]->s0))))
			return (-1);
		if (!(bff[fd]->a = 0) && !bff[fd]->a0)
			return (1);
	}
}
