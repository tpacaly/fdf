#include "fdf.h"

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
/*	e = 0;
	f = 0;
	while(e < kevin)
	{
		while(f++ < a.tailllig)
			ft_affiche("%d ", h[e++]);
		f = 0;
		ft_affiche("\n");
	}*/
	return(a);
}