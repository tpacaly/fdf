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
	xmax = ((x - y) * (a.pixxecart)/2);
	ymax = ((x + y) * (a.pixyecart)/2) + (z * -3);
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
			//	ft_affiche("POINT PLACE : x%d %d y%d %d \n", g, a.xyz, f, a.zyx);
			}
			b++;
		}
//	ft_affiche("FIN\n");
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
			//	ft_affiche("POINT PLACE0 : x%d %d y%d %d\n", g, a.xyz, f, a.zyx);
			}
				c++;
		}
		c = 0;
		b++;
	}
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
	a.tailllig = tailleligne;
	a.compte = compteur;
	ft_affiche("%d %d\n",tailleligne, compteur);
	a = parsing(a, tableau);
	if(a.yy == 0)
		return(ft_affiche("NON\n"));
	a = calcule_taille_ecran(a);
	afficher_points(a);
	free((void**)a.yy);
//	retour = 0;
//	while(retour < a.compte)
//		ft_memdel(&a.yy[retour++]);
	return(tailleligne);
}