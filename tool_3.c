/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:45:22 by akefeder          #+#    #+#             */
/*   Updated: 2021/12/03 17:48:36 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_straddc(char *message, char c)
{
	int		len;
	int		i;
	char	*copy;

	if (message)
	{
		i = 0;
		len = ft_strlen(message);
		if ((copy = (char *)malloc((len + 2) * sizeof(char))) == NULL)
			return (NULL);
		while (message[i] != '\0')
		{
			copy[i] = message[i];
			i++;
		}
		copy[i] = c;
		i++;
		copy[i] = '\0';
		free(message);
	}
	else
	{
		if ((copy = (char *)malloc((2) * sizeof(char))) == NULL)
			return (NULL);
		copy[0] = c;
		copy[1] = '\0';
	}
	return (copy);
}