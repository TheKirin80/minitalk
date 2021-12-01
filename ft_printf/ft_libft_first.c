/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:32:44 by akefeder          #+#    #+#             */
/*   Updated: 2020/02/18 15:46:48 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		signe;
	long	res;
	int		ret;

	i = 0;
	signe = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = signe * (-1);
		i++;
	}
	while (str[i] != '\0' && (str[i] > 47 && str[i] < 58))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	ret = res * signe;
	return (ret);
}

size_t	ft_intlen(long sv)
{
	size_t	len;

	len = 1;
	if (sv < 0)
	{
		sv = -sv;
		len++;
	}
	while (sv > 9)
	{
		sv = sv / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(long n)
{
	size_t	len;
	size_t	i;
	size_t	signe;
	long	sv;
	char	*res;

	sv = (long)n;
	signe = 0;
	i = 0;
	len = ft_intlen(sv);
	if (!(res = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (sv < 0)
	{
		sv = -sv;
		res[signe++] = '-';
	}
	while (len - i > signe)
	{
		res[len - i - 1] = (sv % 10) + '0';
		sv = sv / 10;
		i++;
	}
	res[len] = '\0';
	return (res);
}

int	ft_strcmp(const char s2)
{
	int		test;
	size_t	i;
	char 	*s1;

	s1 = "0123456789+-.*"; 
	i = 0;
	while (s1[i] != '\0')
	{
		test = (unsigned char)s1[i] - (unsigned char)s2;
		if (test == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_strlen(const char *set)
{
	int	i;

	i = 0;
	while (set && set[i] != '\0')
		i++;
	return (i);
}


