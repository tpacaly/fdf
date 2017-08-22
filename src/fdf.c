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

#include "../libft/libft.h"
#include "fdf.h"

int ft_erreur(char **tab, int d, int fd)
{
	while(--d > -1)
		ft_strdel(tab++);
	ft_affiche("ERREUR DE LECTURE DU FICHIER\n");
	close(fd);
	exit(0);
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
	if((retour = get_next_line(fd, &ligne)) == -1)
		return(ft_erreur(tableau, compteur, fd));
	tailleligne = tailletableau(ligne);
	while(retour == 1)
	{
		tableau[compteur] = ligne;
		compteur++;
		retour = get_next_line(fd, &ligne);
		if(retour == -1)
			return(ft_erreur(tableau, compteur, fd));
	//	ft_affiche("%s oui", ligne);
	}
	if(tailleligne == 0 || compteur == 0)
		return(ft_erreur(tableau, compteur, fd));
	close(fd);
	a.tailllig = tailleligne;
	a.compte = compteur;
	ft_affiche("%d %d\n",tailleligne, compteur);
	a = parsing(a, tableau);
	while(1)
	{
		;
	}
	if(a.yy == 0)
		return(ft_affiche("FICHIER NON VALIDE\n"));
	a = calcule_taille_ecran(a);
	afficher_points(a);
	compteur = a.compte;
	while(compteur-- <= 0)
		ft_strdel(&tableau[compteur]);
	retour = 0;
	//while(retour < a.compte)
	//	ft_strdel(a.yy+(retour*a.compte));
	return(tailleligne);
}

static int	ft_red_cross(void)
{
	exit(0);
	return (0);
}

int main(int c, char **v)
{
	t_gene *b;
	t_gene a;

	if (!(b = (t_gene*)malloc(sizeof(t_gene))))
		exit(0);
	a = *b;
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
