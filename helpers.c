/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:31:58 by rili              #+#    #+#             */
/*   Updated: 2017/03/19 19:02:44 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	sudokuprint(char grid[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(grid[i][j]);
			if (j != 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		rowcheck(char grid[9][9], int row, int num)
{
	int col;

	col = 0;
	while (col < 9)
	{
		if (grid[row][col] == num + '0')
			return (1);
		col++;
	}
	return (0);
}

int		colcheck(char grid[9][9], int col, int num)
{
	int row;

	row = 0;
	while (row < 9)
	{
		if (grid[row][col] == num + '0')
			return (1);
		row++;
	}
	return (0);
}

int		boxcheck(char grid[9][9], int startrow, int startcol, int num)
{
	int row;
	int col;

	row = 0;
	col = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			if (grid[row + startrow][col + startcol] == num + '0')
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}

int		placeable(char grid[9][9], int row, int col, int num)
{
	return ((!(rowcheck(grid, row, num))) && (!colcheck(grid, col, num))
			&& (!(boxcheck(grid, row - (row % 3), col - (col % 3), num))));
}
