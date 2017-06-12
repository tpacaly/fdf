/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 19:18:43 by tpacaly           #+#    #+#             */
/*   Updated: 2017/06/12 17:28:47 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_red_cross(void)
{
	exit(0);
	return (0);
}

int main(int c, char **v)
{
	t_gene a;
	if(c != 2)
		return(0);
	if((a.mlx = mlx_init()) == 0)
		return(ft_affiche("mlx_init = 0\n"));
	a.map = mlx_new_window(a.mlx, MAX_X, MAX_Y, "FDF");
	mlx_hook(a.map, 17, 0, ft_red_cross, 0);
	if(liremap(v[1], a) == 0)
		return(0);
//	mlx_loop_hook(a.mlx, main_loop, (void *)&a);
	mlx_loop(a.mlx);
	mlx_destroy_image(a.mlx, a.img);
	mlx_destroy_window(a.mlx, a.map);

	exit(0);
}
