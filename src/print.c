#include "fdf.h"

int		trace_point(t_gene a, int x, int y, int couleur)
{
	if(x > a.max || x < 0 || y == 0 || y > a.may)
		return(-1);
	return(mlx_pixel_put(a.mlx, a.map, x, y, couleur));
}

void	trace_ligne_verticale(t_gene a, int x, int ymin, int ymax, int color)
{
	ymin--;
	while(++ymin <= ymax)
		trace_point(a, x, ymin, color);
}

void	trace_ligne(t_gene a, int xmin, int xmax, int ymin, int ymax, int color)
{
//	if(xmin < -0x200 || xmax > MAX_X || ymin < -0x80 || ymax > MAX_Y)
//		return((void)ft_affiche("point qui depasse %d %d %d %d\n", xmin, xmax, ymin, ymax));
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

t_gene			calcule_taille_ecran(t_gene a)
{
	int ecarty;
	int debutx;
	int ecartx;
	int debuty;

	debutx = 0;
	debuty = 0;
	ecarty = 0;
	ecartx = 0;
	ft_affiche("%d %d %d %d\n", debutx, debuty, ecartx, ecarty);
	ecartx = ((MAX_X-0x200) / a.tailllig);
	debutx = ((MAX_X-0x200) % a.tailllig) + 0x100;
	ecarty = ((MAX_Y-0x100) / a.compte);
	debuty = (((MAX_Y-0x100) % a.compte) / 2) + 0x80;
	a.pixxecart = ecartx;// /2;
	a.pixxdebut = debutx *2;
	a.pixyecart = ecarty /2;
	a.pixydebut = debuty*2;
	ecartx *= a.tailllig;
	ecartx += debutx;
	ecarty *= a.compte;
	ecarty += debuty;
	ft_affiche("%d %d %d %d\n", debutx, debuty, ecartx, ecarty);
//	trace_ligne(a, debutx, ecartx, debuty, debuty, 0xffff);
//	trace_ligne_verticale(a, ecartx, debuty, ecarty, 0xffff);
//	trace_ligne(a, debutx, ecartx, ecarty, ecarty, 0xffff);
//	trace_ligne_verticale(a, debutx, debuty, ecarty, 0xffff);
	return(a);
}