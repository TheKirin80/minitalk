/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:41:20 by akefeder          #+#    #+#             */
/*   Updated: 2020/02/18 17:44:03 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_beg_end_zero(const char *set, int *i, Element *objet)
{
	while (set[*i] == '-' || set[*i] == '0')
	{
		if (objet->lock != TRUE)
		{
			if (set[*i] == '-')
			{
				objet->begin_end = 1;
				objet->zero = 0;
				objet->lock = TRUE;
			}
			else
				objet->zero = 1;
		}
		(*i)++;
	}
}

void detect_param_elem(const char *set, int *i, va_list ap, Element *objet)
{
	int		j;

	j = 0;
	//Etape 1: Position debut fin / espace ou zero 
	ft_beg_end_zero(set, i, objet);
	//printf("zero = %i\nlock = %i\nbegin_end = %i\n", objet->zero, objet->lock, objet->begin_end);
	while (set[*i + j] != '\0' && (objet->hflag = ft_strcmp(set[*i + j])) != 1)
		j++;
	objet->hint_wp = j;
	if (objet->hflag == 0)
	{
		objet->contenu = (char *)malloc(1 * sizeof(char));
		(objet->contenu)[0] = '\0';
		*i = *i + j;
	}
	else
	{
		if (objet->hint_wp > 0)
			rempli_width(set, i, objet, ap);
		//printf("\n|%c|\n",set[(*i)]);
		rempli_contenu(objet, ap, set[(*i)]);
		(*i)++;
		//printf("\n|%c|\n",set[(*i)]);
	}
	objet->length = ft_len(objet);
}

void	init_element(Element *objet)
{
	objet->hflag = 0;
	objet->contenu = NULL;
	objet->precision = -1;
	objet->width = -1;
	objet->length = 0;
	objet->begin_end = 0;
	objet->zero = 0;
	objet->hint_wp = 0;
	objet->pos_k = 0;
	objet->lock = 0;
	objet->neg = 0;
	objet->flag = 0;
	objet->bsz = 0;
	objet->hexa = 0;
	objet->fhexa = 0;
}


int write_param(const char *set, int *i, va_list ap)
{
	Element	objet;
	int		j;
	j = 0;
	if (set[++(*i)] == '\0')
	{
		write(1, "%", 1);
		return (1);
	}
	init_element(&objet);
	detect_param_elem(set, i, ap, &objet);
	if (objet.bsz == 1 && objet.begin_end == 1)
		write(1, &(objet.contenu)[j++], 1);
	while ((objet.contenu)[j] != '\0')
	{
		write(1, &(objet.contenu)[j], 1);
		j++;
	}
	if (objet.bsz == 1 && objet.begin_end == 0)
		write(1, &(objet.contenu)[j], 1);
	free(objet.contenu);
	return (objet.length);
}

int	ft_printf(const char *set, ...)
{
	va_list	ap;
	int		res;
	int		i;
	int		j;

	va_start(ap, set);
	i = 0;
	res = 0;
	while (((j = 0) == 0) && set && set[i] != '\0')
	{
		if (set[i] != '%')
		{
			write(1, &set[i], 1);
			j = 1;
			i++;
		}
		else
			j = write_param(set, &i, ap);
		res = res + j;
	}
	va_end(ap);
	return (res);
}
