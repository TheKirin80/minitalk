/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_tool2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:57:03 by akefeder          #+#    #+#             */
/*   Updated: 2020/02/04 19:50:00 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_zero_ox(Element *objet)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 2;
	if ((res = (char *)malloc((objet->precision + 3) * sizeof(char))) != NULL)
	{
		res[i++] = '0';
        res[i++] = 'x';
		while (i <= ((objet->precision) + 3) - objet->length)
        {
			res[i] = '0';
            i++;
        }
		while (i < (objet->precision) + 3)
			res[i++] = (objet->contenu)[j++];
		res[i] = '\0';
        free(objet->contenu);
		objet->contenu = res;
		objet->length = ft_strlen(objet->contenu);
	}
}

void    ft_cut_ox(Element *objet)
{
    char    *res;

    if ((res = (char *)malloc(3 * sizeof(char))) != NULL)
    {
        res[0] = '0';
        res[1] = 'x';
        res[2] = '\0';
        free(objet->contenu);
        objet->contenu = res;
    }
}
void	modif_pointer(Element *objet)
{
	int		range;
	
	objet->length = ft_strlen(objet->contenu);
	if (((objet->length) - 2) < objet->precision)
		ft_add_zero_ox(objet);
    if (objet->precision == 0)
        ft_cut_ox(objet);
    objet->length = ft_strlen(objet->contenu);
	range = ft_sup(objet->precision, objet->width, objet->length);
	//printf("\nprecision = %i\nzero = %i\n", objet->precision,objet->zero);
	if (objet->width > objet->length)
	{
		//printf("0je suis la\n");
		if (objet->begin_end == 1)
		{
			//printf("1je suis la\n");
			ft_rempli_ifi(objet, range, ' ');
		}
		else if (objet->zero == 1 && objet->precision > -1)
		{
			//printf("2je suis la\n");
			ft_rempli_fi(objet, range, '0');
		}
		else
		{
			//printf("3je suis la\n");
			ft_rempli_fi(objet, range, ' ');
		}
	}
	//printf("\ncontenu = |%s|\n", objet->contenu);
}

