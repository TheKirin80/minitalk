/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_tool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:08:55 by akefeder          #+#    #+#             */
/*   Updated: 2020/02/18 18:20:33 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_zero(Element *objet)
{
	char	*res;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if ((res = (char *)malloc((objet->precision + 1) * sizeof(char))) != NULL)
	{
		while (++i < objet->precision - objet->length)
			res[i] = '0';
		while (i < objet->precision)
			res[i++] = (objet->contenu)[j++];
		res[i] = '\0';
		free(objet->contenu);
		objet->contenu = res;
		objet->length = ft_strlen(objet->contenu);
	}
}

void	ft_rempli_fi_num(Element *objet)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 1;
	if ((res = (char *)malloc((objet->width + 2) * sizeof(char))) != NULL)
	{
		res[i] = '-';
		while (++i <= ((objet->width)) - objet->length)
			res[i] = '0';
		while (i < (objet->width) + 1)
			res[i++] = (objet->contenu)[j++];
		res[i] = '\0';
		free(objet->contenu);
		objet->contenu = res;
		objet->length = ft_strlen(objet->contenu);
	}
}

void	ft_add_zero_n(Element *objet)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 1;
	if ((res = (char *)malloc((objet->precision + 2) * sizeof(char))) != NULL)
	{
		res[i] = '-';
		while (++i <= ((objet->precision) + 1) - objet->length)
			res[i] = '0';
		while (i < (objet->precision) + 1)
			res[i++] = (objet->contenu)[j++];
		res[i] = '\0';
		free(objet->contenu);
		objet->contenu = res;
		objet->length = ft_strlen(objet->contenu);
	}
}

void ft_zero(Element *objet)
{
	if (objet->precision != 1)
	{
		objet->contenu[0] = '\0';
		objet->length = ft_strlen(objet->contenu);
	}
}

void	modif_number(Element *objet, int i)
{
	int		range;
	
	objet->length = ft_strlen(objet->contenu);
	if ((i == 6 || i == 7) && objet->hexa != 0)
		objet->fhexa = 1;
	if (objet->neg == 1 && (((objet->length) - 1) < objet->precision))
		ft_add_zero_n(objet);
	else if (objet->length < objet->precision)
		ft_add_zero(objet);
	else if (ft_atoi(objet->contenu) == 0 && objet->precision >= 0
		&& objet->fhexa == 0)
		ft_zero(objet);
	range = ft_sup(objet->precision, objet->width, objet->length);
	if (objet->width > objet->length)
	{
		if (objet->begin_end == 1)
			ft_rempli_ifi(objet, range, ' ');
		else if (objet->zero == 1 && objet->neg == 1 && objet->precision == -1)
			ft_rempli_fi_num(objet);
		else if (objet->zero == 1 && objet->precision == -1)
			ft_rempli_fi(objet, range, '0');
		else
			ft_rempli_fi(objet, range, ' ');
	}
}