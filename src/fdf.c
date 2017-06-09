/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 19:18:43 by tpacaly           #+#    #+#             */
/*   Updated: 2017/06/09 06:26:46 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fdf.h"

int		trace_point(t_gene a, int x, int y, int couleur)
{
	if(x > a.max || x < 0 || y == 0 || y > a.may)
		return(-1);
	return(mlx_pixel_put(a.mlx, a.map, x, y, couleur));
}

void	trace_ligne(t_gene a, int xmin, int xmax, int ymin, int ymax, int color)
{
	ft_affiche("%d %d %d %d\n", xmin, xmax, ymin, ymax);
	int x;
	int y;
	double b;
	double c;

	x = 0;
	y = 0;
	b = (double) (ymax-ymin)/(xmax-xmin);
	c = ymin - (b*xmin);
	x = xmin;
	while(x <= xmax)
	{
		y = (int) (b * x + c);
		trace_point(a, x, y, color);
		x++;
	}
}

void	trace_point_special_fdf(t_gene a, int x, int y, int z, int couleur)
{
	int b = x + (z*4);
	int c = y + (z*6);
	trace_ligne(a, x, b, y, c, couleur);
}

static int	ft_red_cross(void)
{
		exit(0);
			return (0);
}

int 	main_loop(void *a)
{
	t_gene *b = a;

	return(b->tailllig);
}

int	tailletableau(char *a)
{
	int c= 0;
	int b = 0;
	while(a[b])
	{
		if((a[b] < 0x3a && a[b] > 0x2f) || a[b] == 0x2d || a[b] == 0x2d)
		{
			c++;
			while((a[b] < 0x3a && a[b] > 0x2f) || a[b] == 0x2d || a[b] == 0x2d)
				b++;
		}
		else if(a[b] == ' ')
			b++;
		else
			return(0);
	}
	return(c);
}

void afficher_carte(int a, int b, t_gene c)
{
//	int d;
//	int e;
	int g;

//	d = 780 / a;
	g = b;
//	e = 780 / b; // e pas toucher
	// s adresse a remplir

	while(a-- != 0)
	{
		while(b-- != 0)
		{
			trace_point_special_fdf(c, a, b, 0x10, 0x00ff00ff);
		}
		b = g;
	}
}

int	liremap(char *fichier, t_gene a)
{
	int fd = 0;
	char *ligne = 0;
	int retour = 0;
	int compteur = 0;
	int tailleligne = 0;

	if((fd = open(fichier, 2)) == -1)
		return(ft_affiche("FICHIER NON TROUVE\n"));
	retour = get_next_line(fd, &ligne);
	tailleligne = tailletableau(ligne);
	while(retour == 1)
	{
		compteur++;
		retour = get_next_line(fd, &ligne);
	}
	if(retour == -1 || ligne[0] != 0)
		return(ft_affiche("ERREUR DE LECTURE DU FICHIER\n"));
	close(fd);
	ft_affiche("%d %d\n",tailleligne, compteur);
	afficher_carte(tailleligne, compteur, a);
	a.tailllig = tailleligne;
	a.compte = compteur;
	return(tailleligne);
}

int main(int c, char **v)//int c, char **v)
{
	t_gene a;
	a.max = MAX_X;
	a.may = MAX_Y;
//	int c = 0x7fffffff;
//	int b;
	if(c != 2)
		return(0);
	if((a.mlx = mlx_init()) == 0)
		return(ft_affiche("mlx_init = 0\n"));
	a.map = mlx_new_window(a.mlx, MAX_X, MAX_Y, "FDF");
//	a.img = mlx_new_image(a.mlx, 2560, 1440);
	mlx_hook(a.map, 17, 0, ft_red_cross, 0);//read(0, &b, 1);
	if(liremap(v[1], a) == 0)
		return(0);
//	int ad = 100; // x
//	int cd = 800; //y
//	int bd = 8;
//	while(bd-- != 0)
//	{
//		trace_point_special_fdf(a, ad, cd, 10, 0x00ffffff);
//		ad -=100;
//		cd -= 100;
//	}
//	trace_point(a, 100, 100, 0x00ff00ff);
//	trace_point(a, 700, 700, 0x0000ff00);
//	trace_ligne(a, 100, 700, 100, 700, 0);
	mlx_loop_hook(a.mlx, main_loop, (void *)&a);
	mlx_loop(a.mlx);
	mlx_destroy_image(a.mlx, a.img);
	mlx_destroy_window(a.mlx, a.map);

	exit(0);
}
