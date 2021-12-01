/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_third.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:41:17 by akefeder          #+#    #+#             */
/*   Updated: 2020/02/04 18:35:00 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ox(char *save, int length)
{
	char	*buf;
	int		i;
	int		j;

	if (!(buf = (char *)malloc((length + 3) * sizeof(char))))
		return(NULL);
	i = 2;
	j = 0;
	buf[0] = '0';
	buf[1] = 'x';
	while (save[j] != '\0')
	{
		buf[i] = save[j];
		i++;
		j++;
	}
	buf[i] = '\0';
	free(save);
	return(buf);
}

size_t	ft_pointlen(unsigned long sv)
{
	size_t	len;

	len = 1;

	while (sv > 15)
	{
		sv = sv / 16;
		len++;
	}
	return (len);
}

char	*ft_pointoa(unsigned long n, char *set)
{
	size_t	len;
	size_t	i;
	char	*res;

	i = 0;
	len = ft_pointlen(n);
	if (!(res = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (len - i > 0)
	{
		res[len - i - 1] = set[n % 16];
		n = n / 16;
		i++;
	}
	res[len] = '\0';
	return (res);
}

char	*ft_strdup(const char *s)
{
	int	len;
	int		i;
	char	*cpy;

	i = 0;
	len = ft_strlen(s);
	if ((cpy = (char *)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int		ft_len(Element *objet)
{
	int	i;

	i = 0;
	if (objet->bsz == 1 && objet->begin_end == 1)
		i++;
	while((objet->contenu)[i] != '\0')
		i++;
	if (objet->bsz == 1 && objet->begin_end == 0)
		i++;
	return i;
}