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

void	free_tab(char **t)
{
	int i;

	i = 0;
	while (t[i])
	{
		ft_strdel(&t[i]);
		i++;
	}
	ft_strdel(&t[i]);
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
	while(f < a.compte)
	{
		buff = ft_strsplit(vinyl[f], ' ');
		e = 0;
		if(buff[e])
		{
			while(buff[e])
			{
				z = ft_atoi(buff[e]);
				kevin = ((f * a.tailllig) + e); // f = y, e = x
				h[kevin] = z;
				e++;
			}
		//	kevin = 0;
		//	while(kevin < a.compte)
		//		ft_memdel((void**)&buff[kevin++]);
		//	read(0,0,0);
		}
			ft_strdel(&vinyl[f++]);
			free_tab(buff);
			free(buff);
			buff = 0;
	}
	ft_memdel((void**)&h);
	return(a);
}