/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:31:58 by rili              #+#    #+#             */
/*   Updated: 2017/03/19 19:15:07 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		find_next_location(char grid[9][9], int *row, int *col)
{
	*row = 0;
	while (*row < 9)
	{
		*col = 0;
		while (*col < 9)
		{
			if (grid[*row][*col] == '.')
				return (1);
			(*col)++;
		}
		(*row)++;
	}
	return (0);
}

int		solve(char grid[9][9])
{
	int		row;
	int		col;
	int		num;

	if (find_next_location(grid, &row, &col) == 0)
		return (1);
	num = 1;
	while (num < 10)
	{
		if (placeable(grid, row, col, num) == 1)
		{
			grid[row][col] = num + '0';
			if (solve(grid))
				return (1);
			grid[row][col] = '.';
		}
		num++;
	}
	return (0);
}

void	gridinit(char grid[9][9], char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			grid[i][j] = argv[i + 1][j];
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	grid[9][9];

	if (argc != 10)
		ft_putstr("Error\n");
	else if (checkargv(argv) == 0)
		ft_putstr("Error\n");
	else
	{
		gridinit(grid, argv);
		if (solve(grid) == 1 && finalcheck(grid) == 1)
			sudokuprint(grid);
		else
			ft_putstr("Error\n");
	}
	return (0);
}
