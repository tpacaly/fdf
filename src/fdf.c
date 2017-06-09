/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 19:18:43 by tpacaly           #+#    #+#             */
/*   Updated: 2017/06/10 01:12:27 by tpacaly          ###   ########.fr       */
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
	if(xmin <= 0 || xmax > MAX_X || ymin <= 0 || ymax > MAX_Y)
		return((void)ft_affiche("vv%d %d %d %d\n", xmin, xmax, ymin, ymax));
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

int     trace_point_0(t_gene a, int x, int y, int couleur)
{
	int b = 0;
	int c = 0;
	if(x == 0 && y == 0)
	{
		a.xyz = 2048;
		a.zyx = 1440;
		return(trace_point(a, x, y, couleur));
	}
	else
	{
		b = a.xyz;
		a.xyz = x;
		c = a.zyx;
		a.zyx = y;
		trace_ligne(a, b, x, c, y, 0xff00ff);
	//  x += 200;
	//  y +=200;
	}
	return(trace_point(a, x, y, couleur));
}

void	trace_point_special_fdf(t_gene a, int x, int y, int z, int couleur)
{
	int b = x + (z*2);
	int c = y + (z*3);
	trace_ligne(a, b, x, c, y, couleur);
}

int 	ft_prendretaillebase(unsigned int nb, unsigned int base)
{
	int a = 0;

	while(nb % base > 1)
	{
		nb = nb / base;
		a++;
	}
	return(a);
}


static int	ft_red_cross(void)
{
	exit(0);
	return (0);
}

int 	main_loop(void *a)
{
	t_gene *b = a;

	return(b->tailllig * 0);
}

int	tailletableau(char *a)
{
	int c = 0;
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

void	affiche_points_hauteur(char *a, t_gene b, int e)
{
	int d;
	int c = 0;
	int x = (c*b.pixxecart)+b.pixxdebut;
	int y = (e*b.pixyecart)+b.pixydebut;
	while(a[c])
	{
		if((d = ft_atoi(&a[c])) == 0)
			c++;
		else
		{
			ft_affiche("NEED %d\n", d);
			trace_point_special_fdf(b,x,y,(d<<4), 0xffffff); // c  + f = x, e = y
			while(ft_atoi(&a[c]) == d)
				c++;
		}
	}
}

void	afficher_points(t_gene a, char **vinyl)
{
	int b;
	int c;
	int f;
	int g;
	int z;

	z = 0;
	b = 0; // x
	f = 0;
	g = 0;
	c = 0; // y
	while(vinyl[f])
	{
		while(vinyl[f][g])
		{
			while(vinyl[f][g] == ' ')
				g++;
			z = ft_atoi(&vinyl[f][g]);
			trace_point_0(a, ((b - f) * 60), (((b + f) * 30) + (z * -10)), 0xffffff);
			b++;
			g++;
			ft_affiche("POINT PLACE : x%d y%d z%d\n", b, c, z);
		}
		f++;
		b = 0;
		g = 0;
	}

	/*	b = MAX_X-0x80 ;
		a.pixxecart = b / (a.tailllig-1) ;
		b %= a.tailllig;
		b+= 0x80;
		a.pixxdebut = b / 2;
		b = MAX_Y-0x80 ;
		a.pixyecart = b / (a.compte-1);
		b %= a.compte;
		b+= 0x80;
		a.pixydebut = b / 2;
	//	a.pixyecart = MAX_Y-0x100 / a.compte;
	//	a.pixydebut = ((MAX_Y-0x100 % a.compte) / 2 ) + 0x80;
	ft_affiche("%d %d %d %d\n",a.pixxecart,a.pixxdebut, a.pixyecart,a.pixydebut);
	b = 0;
	c = 0;
	d = a.pixxdebut;
	e = a.pixydebut;
	while(b++ != a.compte)
	{
	affiche_points_hauteur(vinyl[b], a, b);
	while(c++ != a.tailllig)
	{
	//	int		trace_point(t_gene a, int x, int y, int couleur);
	trace_point(a, d, e, 0xff00ff);
	d+= a.pixxecart;
	}
	c = 0;
	d = a.pixxdebut;
	e+= a.pixyecart;
	}
	//	while()*/
}

int	liremap(char *fichier, t_gene a)
{
	int fd = 0;
	char *ligne = 0;
	char *tableau[MAX_LIGNES];
	int retour = 0;
	int compteur = 0;
	int tailleligne = 0;

	if((fd = open(fichier, 2)) == -1)
		return(ft_affiche("FICHIER NON TROUVE\n"));
	retour = get_next_line(fd, &ligne);
	tailleligne = tailletableau(ligne);
	while(retour == 1)
	{
		tableau[compteur] = ligne;
		compteur++;
		retour = get_next_line(fd, &ligne);
	}
	tableau[compteur+1]=0;
	if(retour == -1 || ligne[0] != 0)
		return(ft_affiche("ERREUR DE LECTURE DU FICHIER\n"));
	close(fd);
	ft_affiche("%d %d\n",tailleligne, compteur);
	a.tailllig = tailleligne;
	a.compte = compteur;
	afficher_points(a, tableau);
	//	afficher_carte(a, tableau);
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
