/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:23:54 by akefeder          #+#    #+#             */
/*   Updated: 2021/12/03 17:44:09 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isnum(int c)
{
	int valide;

	if (c > 47 && c < 58)
		valide = 0;
	else
		valide = 1;
	return (valide);
}

int ft_stisnum(char *message)
{
	int	i;
	int valide;

	i = 0;
	while (message[i] != '\0')
	{
		valide = ft_isnum(message[i]);
		if (valide == -1)
			return (valide);
		i++;
	}
	return (valide);
}

int ft_strlen(char *message)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
		i++;
	return (i);
}

void    ft_putstr_fd(char *s, int fd)
{
        int  len;

        if (s != NULL && fd >= 0)
        {
                len = ft_strlen(s);
                write(fd, s, len);
        }
}

char	*ft_strdup(char *s)
{
	size_t	len;
	size_t	i;
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