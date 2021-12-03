/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:12:48 by akefeder          #+#    #+#             */
/*   Updated: 2021/12/03 19:57:06 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define EXIT_ERROR 1
# define ERROR -1
# define OK 0

void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *message);
int		ft_stisnum(char *message);
char	*ft_strdup(char *s);
int		ft_atoi(char *str);
int		ft_islong(char *str);
void	ft_putnbr_fd(int n, int fd);
char	*ft_straddc(char *message, char c);
#endif