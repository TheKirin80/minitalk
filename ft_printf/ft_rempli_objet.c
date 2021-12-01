/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rempli_objet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 02:57:29 by akefeder          #+#    #+#             */
/*   Updated: 2020/02/18 16:52:14 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    rempli_width(const char *set,int *i, Element *objet, va_list ap)
{
	int cpt;
	char unit[objet->hint_wp + 1];

	objet->pos_k = -1;
	cpt = -1;
	while (++objet->pos_k < objet->hint_wp && objet->flag == 0)
	{
		if (set[*i + objet->pos_k] == '.' && (objet->pos_k + 1) < objet->hint_wp)
			objet->flag = 1;
		else if (set[*i + objet->pos_k] == '.')
			objet->precision = 0;
	}
	//printf("\n|%c|\n|%c|\n|", set[*i],set[(*i) - 1]);
	if (set[*i] == '*')
		cpt = ft_abs_width(va_arg(ap, int), objet);
	else
	{
		while (++cpt < objet->pos_k)
			unit[cpt] = set[*i + cpt];
		unit[cpt] = '\0';
		objet->width = ft_atoi(unit);
	}
	if (objet->flag == 1 && ft_isnum(set[(objet->pos_k) + *i]) == TRUE)
		cpt = cpt + rempli_preci(set, i, objet, ap);
	*i = *i + cpt;
	//printf("\nprecision = %i\nwidth = %i\n|%c|\n", objet->precision, objet->width, set[*i]);
}

int    rempli_preci(const char *set,int *i, Element *objet, va_list ap)
{
	char    unit[objet->hint_wp + 1];
	int     cpt;

	cpt = 0;
	//printf("\n|%c|\n", set[(*i) + objet->pos_k]);
	if (set[(*i) + (objet->pos_k)] == '*')
	{
		objet->precision = ft_abs(va_arg(ap, int));
		//printf("2je suis dans la boucle de precis\n");
		cpt = 1;
	}
	else
	{
		//printf("3je suis dans la boucle de precis\n");
		while (objet->pos_k < objet->hint_wp)
		{
			unit[cpt] = set[*i + objet->pos_k];
			(objet->pos_k)++;
			cpt++;
		}
		unit[cpt] = '\0';
		//printf("preci unit = %s\n", unit);
		objet->precision = ft_atoi(unit);
	}
	return (cpt);
}

void    rempli_contenu(Element *objet, va_list ap, char c)
{
	int	i;
	char *set;

	set = "cspdiuxX%";
	i = 0;
	while (set[i] != '\0' && set[i] != c )
		i++;
	if (i == 0 || i == 8 || i == 9)
		insert_char(objet, ap, c, i);
	else if (i == 1)
		insert_string(objet, ap);
	else if (i == 2)
		insert_pointer(objet, ap);
	else if (i == 3 || i == 4 || i == 5)
		insert_nbr(objet, ap, i);
	else if (i == 6 || i == 7)
		insert_hexa(objet, ap, i);
	//printf("\n rempli contenu = |%s|\n", objet->contenu);
	if (objet->width >=0 || objet->precision>=0)
		appli_pre_width(objet, i);
	//printf("\nrempli apres appli contenu = |%s|\n", objet->contenu)
}

int		ft_abs_width(int x, Element *objet)
{
	if (x >= 0)
		objet->width = x;
	else
	{
		objet->width = -x;
		objet->begin_end = 1;
	}
	if (objet->flag == 1 || objet->precision == 0)
		return (2);
	else
		return (1);
}

void	appli_pre_width(Element *objet, int i)
{
	if (i == 0 || i == 1 || i == 8)
		modif_string(objet);
	if (i == 3 || i == 4 || i == 5 || i == 6 || i == 7)
		modif_number(objet, i);
	if (i == 2)
		modif_pointer(objet);

	//printf("appli contenu = |%s|\n", objet->contenu);
}