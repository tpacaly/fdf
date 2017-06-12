/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 19:18:43 by tpacaly           #+#    #+#             */
/*   Updated: 2017/06/12 03:31:32 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fdf.h"

int		trace_point(t_gene a, int x, int y, int couleur)
{
	x+= 0x200;
	y+= 0x80;
	if(x > a.max || x < 0 || y == 0 || y > a.may)
		return(-1);
	return(mlx_pixel_put(a.mlx, a.map, x, y, couleur));
}

void	trace_ligne(t_gene a, int xmin, int xmax, int ymin, int ymax, int color)
{
	if(xmin < -0x200 || xmax > MAX_X || ymin < -0x80 || ymax > MAX_Y)
		return((void)ft_affiche("point qui depasse %d %d %d %d\n", xmin, xmax, ymin, ymax));
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

t_gene		calcule_point(t_gene a, int x, int y)
{
	int xmax;
	int ymax;
	int *tableauvaleurs;
	int c;
	int z;

	tableauvaleurs = a.yy;
	xmax = 0;
	ymax = 0;
	c = (a.tailllig * y) + x;
	z = tableauvaleurs[c];
	xmax = ((x - y) * 30);
	ymax = ((x + y) * 15) + (z * -5);
	a.xyz = xmax;
	a.zyx = ymax;
	return(a);
}

t_gene		trace_point_0(t_gene a, int x, int y, int couleur)
{
	int b = 0;
	int c = 0;
	b = a.xyz;
	a.xyz = x;
	c = a.zyx;
	a.zyx = y;
	trace_ligne(a, b, x, c, y, 0xff00ff);
	trace_point(a, x, y, couleur);
	return(a);
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

void	afficher_points(t_gene a)
{
	int b;
	int c;
	int f;
	int g;
	int z;
	int *h;
	int kevin;

	h = a.yy;
	z = 0;
	b = 0; // x
	f = 0;
	g = 0;
	c = 0; // y
	a.zyx = 0;
	a.xyz = 0;
	while(c < a.compte)
	{
		while(b < a.tailllig)
		{
			kevin = ((c * a.tailllig) + b);
			z = h[kevin];
			z *= -5;
			a = trace_point_0(a, ((b - c) * 30), (((b + c) * 15) + z), 0xffffff);
			ft_affiche("POINT PLACE : x%d y%d z%d\n", b, c, z);
			b++;
		}
	ft_affiche("FIN\n");
		b = 0;
		c++;
	}
//	return;
	b = 0;
	a.zyx = 0;
	a.xyz = 0;
	c = 0;
	while(b < a.tailllig)
	{
		while(c < a.compte)
		{
			if(c != 0)
			{
				a = calcule_point(a, b, (c-1));
				g = a.xyz;
				f = a.zyx;
				a = calcule_point(a, b, c);
				trace_ligne(a, a.xyz, g, a.zyx, f, 0xffffff);
			//	a = trace_point_1(a, ((b - c) * 30), (((b + c) * 15) + z), 0xffffff);
				ft_affiche("POINT PLACE0 : x%d %d y%d %d\n", g, a.xyz, f, a.zyx);
			}
				c++;
		}
		c = 0;
		b++;
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

t_gene	parsing(t_gene a, char **vinyl)
{
	int *h;
	int f;
	int e;
	int x;
	int z;
	int kevin;
	char **buff;

	f = 0;
	kevin = 0;
	z = 0;
	x = 0;
	e = a.compte * a.tailllig;// * 3;
	if((h = malloc(sizeof(int*) * e)) == NULL)
		return(a);
	a.yy = h;
	e = 0;
	while(f < a.compte)
	{
		buff = ft_strsplit(vinyl[f], ' ');
		e = 0;
		if(buff)
		{
			while(buff[e])
			{
				z = ft_atoi(buff[e]);
				// f = y, e = x
				kevin = ((f * a.tailllig) + e);
				h[kevin] = z;
				e++;
			}
		}
		else
			;
		f++;
		//	kevin = ((y * tailllig) +x
	}
	e = 0;
	f = 0;
	while(e < kevin)
	{
		while(f++ < a.tailllig)
			ft_affiche("%d ", h[e++]);
		f = 0;
		ft_affiche("\n");
	}
	return(a);
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
	a = parsing(a, tableau);
	if(a.yy == 0)
		return(ft_affiche("NON\n"));
	afficher_points(a);
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
	free(a.yy);
	mlx_loop_hook(a.mlx, main_loop, (void *)&a);
	mlx_loop(a.mlx);
	mlx_destroy_image(a.mlx, a.img);
	mlx_destroy_window(a.mlx, a.map);

	exit(0);
}
