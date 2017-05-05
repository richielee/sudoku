/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:27:39 by rili              #+#    #+#             */
/*   Updated: 2017/03/19 18:33:14 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_checkvalue(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '1' && str[i] <= '9') && (str[i] != '.'))
			return (0);
		i++;
	}
	return (1);
}

int		checkargv(char **argv)
{
	int i;

	i = 1;
	while (i < 10)
	{
		if (ft_strlen(argv[i]) != 9 || ft_checkvalue(argv[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}
