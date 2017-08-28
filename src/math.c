#include "fdf.h"

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
	xmax = ((x - y) * (a.pixxecart)/MULTI_X);
	ymax = ((x + y) * (a.pixyecart)/MULTI_Y) + (z * MULTI_Z);
	xmax+= a.pixxdebut;
	ymax+= a.pixydebut;
	a.xyz = xmax;
	a.zyx = ymax;
	return(a);
}

void	afficher_points(t_gene a)
{
	int b;
	int c;
	int f;
	int g;
	int z;
	int *h;

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
			if(b != 0)
			{
				a = calcule_point(a, (b-1), c);
				g = a.xyz;
				f = a.zyx;
				a = calcule_point(a, b, c);
				trace_ligne(a, g, a.xyz, f, a.zyx, 0xffffff);
			}
			b++;
		}
		b = 0;
		c++;
	}
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
			}
				c++;
		}
		c = 0;
		b++;
	}
	c = a.compte;
	b = 0;
/*	while(c-- <= 0)
	{
		free(&h[b*c]);
	}
	free(h);
	h = 0;
*/}