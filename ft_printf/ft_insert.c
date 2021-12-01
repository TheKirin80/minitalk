/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 07:08:28 by akefeder          #+#    #+#             */
/*   Updated: 2020/02/18 17:41:29 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void insert_char(Element *objet, va_list ap, char c, int i)
{
	char *res;

	res = (char *)malloc(2 * sizeof(char));
	if (i == 0)
	{
		res[0] = va_arg(ap, int);
		if (res[0] == 0)
			objet->bsz = 1;
	}
	else if (i == 8)
		res[0] ='%';
	else
		res[0] = c;
	res[1] = '\0';
	objet->contenu = res;
}

void insert_string(Element *objet, va_list ap)
{
	char *res;
	
	res = va_arg(ap, char *);
	if (res == NULL || (objet->contenu = ft_strdup(res)) == NULL)
		objet->contenu = ft_strdup("(null)");
}

void insert_pointer(Element *objet, va_list ap)
{
	void			*buf;
	unsigned long	res;
	char			*save;

	buf = va_arg(ap, void *);
	if (buf == NULL)
		objet->contenu = ft_strdup("0x0");
	else
	{
		res = (unsigned long)buf;
		save = ft_pointoa(res, "0123456789abcdef");
		save = ft_ox(save, ft_strlen(save));
		objet->contenu = save;
	}
}

void insert_nbr(Element *objet, va_list ap, int i)
{
	long d;

	//Voir si ca respecte la casse en cas de unsigned negatif
	if (i == 3 || i == 4)
		d = (long)va_arg(ap, int);
	else
		d = (long)va_arg(ap, unsigned int);
	if (d < 0)
		objet->neg = 1;
	objet->contenu = ft_itoa(d);
}

void insert_hexa(Element *objet, va_list ap, int i)
{
	unsigned int	n;
	char			*hexax;
	char			*hexaX;

	hexax = "0123456789abcdef";
	hexaX = "0123456789ABCDEF";
	n = va_arg(ap, unsigned int);
	objet->hexa = n;
	if (i == 6)
		objet->contenu = ft_hextoa(n, hexax);
	else
		objet->contenu = ft_hextoa(n, hexaX);
	//Prevoir de refaire l'affichage lors des tests finaux
}