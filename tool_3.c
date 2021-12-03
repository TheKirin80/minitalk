/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:45:22 by akefeder          #+#    #+#             */
/*   Updated: 2021/12/03 19:40:38 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_cop(char *message, char *copy, char c)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		copy[i] = message[i];
		i++;
	}
	copy[i] = c;
	i++;
	copy[i] = '\0';
}

char	*ft_straddc(char *message, char c)
{
	int		len;
	char	*copy;

	if (message)
	{
		len = ft_strlen(message);
		copy = (char *)malloc((len + 2) * sizeof(char));
		if (copy == NULL)
			return (NULL);
		ft_cop(message, copy, c);
		free(message);
	}
	else
	{
		copy = (char *)malloc((2) * sizeof(char));
		if (copy == NULL)
			return (NULL);
		copy[0] = c;
		copy[1] = '\0';
	}
	return (copy);
}
