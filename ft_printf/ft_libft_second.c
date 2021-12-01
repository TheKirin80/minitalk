/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:48:28 by akefeder          #+#    #+#             */
/*   Updated: 2020/02/18 17:42:01 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hexlen(unsigned int sv)
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

char	*ft_hextoa(unsigned int n, char *set)
{
	size_t	len;
	size_t	i;
	char	*res;

	i = 0;
	len = ft_hexlen(n);
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

int		ft_abs(int x)
{
	if (x >= 0)
		return (x);
	else
		return (-1);
}

int	ft_isnum(int c)
{
	if ((c > 47 && c < 58) || c == 42)
		return (TRUE);
	else
		return (FALSE);
}

int		ft_sup(int a, int b, int c)
{
	int res;

	if (a >= b)
		res = a;
	else
		res = b;
	if (res < c)
		res = c;
	return (res); 
}
