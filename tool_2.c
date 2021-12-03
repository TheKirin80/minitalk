/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:54:55 by akefeder          #+#    #+#             */
/*   Updated: 2021/12/03 17:39:25 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
        int		i;
        long	signe;
        long	res;
        int		ret;

        i = 0;
        signe = 1;
        res = 0;
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
                || str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
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

long	ft_atoi_lg(char *str)
{
        int		i;
        long	signe;
        long	res;
        int		ret;

        i = 0;
        signe = 1;
        res = 0;
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
                || str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
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

int	ft_islong(char *str)
{
	long	i;
	int j;

	i = 0;
	j = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
                i++;
	if (str[i] == '-' || str[i] == '+')
            i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	if (j > 10)
		return (ERROR);
	i = ft_atoi_lg(str);
	if (i > -2147483649 && i < 2147483648)
		return (OK);
	return (ERROR);
}

void ft_putchar_fd (char c, int fd)
{
	write(fd, &c, 1);
}


void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
			ft_putchar_fd(n + '0', fd);
	}
}

