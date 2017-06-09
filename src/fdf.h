/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 19:28:21 by tpacaly           #+#    #+#             */
/*   Updated: 2017/06/09 02:15:37 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

typedef struct			s_image
{
	int		x;
	int		y;
	char	*buff;
}						t_image;

typedef struct			s_gene
{
	void* mlx;
	void* map;
	t_image* img;
	int max;
	int may;
}						t_gene;

#endif
