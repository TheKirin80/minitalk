/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:54:10 by akefeder          #+#    #+#             */
/*   Updated: 2020/02/04 17:36:02 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rempli_fi(Element *objet, int range, char sep)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if ((res = (char *)malloc((range + 1) * sizeof(char))) != NULL)
		while (i < objet->width - objet->length)
			res[i++] = sep;
		while (i < objet->width)
			{
				res[i++] = (objet->contenu)[j++];
			}
		res[i] = '\0';
		free(objet->contenu);
		objet->contenu = res;
}

void	ft_rempli_ifi(Element *objet, int range, char sep)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if ((res = (char *)malloc((range + 1) * sizeof(char))) != NULL)
		while (i < objet->length)
			res[i++] = (objet->contenu)[j++];
		while (i < objet->width)
			res[i++] = sep;
		res[i] = '\0';
		free(objet->contenu);
		objet->contenu = res;
}

void	ft_cut(Element *objet)
{
	char *cut;
	int i;
	
	i = -1;
	if ((cut = (char *)malloc((objet->precision + 1) * sizeof(char))) != NULL)
	while (++i < objet->precision)
		cut[i] = (objet->contenu)[i];
	cut[i] = '\0';
	free(objet->contenu);
	objet->contenu = cut;
	objet->length = ft_strlen(objet->contenu);
}

void	modif_string(Element *objet)
{
	int		range;
	
	//printf("\n\n modif contenu = %s\n\n", objet->contenu);
	objet->length = ft_strlen(objet->contenu);
	if (objet->bsz == 1)
		(objet->length)++;
	if (objet->precision >= 0 && objet->precision < objet->length)
		ft_cut(objet);
	range = ft_sup(objet->precision, objet->width, objet->length);
	if (objet->width > objet->length)
	{
		if (objet->begin_end == 1)
			ft_rempli_ifi(objet, range, ' ');
		else if (objet->zero == 1)
			ft_rempli_fi(objet, range, '0');
		else
			ft_rempli_fi(objet, range, ' ');
	}
	//printf("\nmodif contenu = |%s|\n", objet->contenu);
}

