/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 19:28:21 by tpacaly           #+#    #+#             */
/*   Updated: 2017/06/09 14:10:15 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MAX_X 1024
# define MAX_Y 720
# define MAX_LIGNES 100
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
	int compte; // nombre de lignes remplies dans le fichier
	int tailllig; // nombre de blocs par ligne
	int pixxecart;
	int pixxdebut;
	int pixyecart;
	int pixydebut;
}						t_gene;

#endif
