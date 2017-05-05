/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:49:31 by rili              #+#    #+#             */
/*   Updated: 2017/03/19 19:15:45 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		frowcheck(char grid[9][9], int row)
{
	int col;
	int i;

	i = 1;
	col = 0;
	while (col < 9)
	{
		i ^= (grid[row][col] - '0');
		col++;
	}
	if (i == 0)
		return (1);
	else
		return (0);
}

int		fcolcheck(char grid[9][9], int col)
{
	int row;
	int i;

	i = 1;
	row = 0;
	while (row < 9)
	{
		i ^= (grid[row][col] - '0');
		row++;
	}
	if (i == 0)
		return (1);
	else
		return (0);
}

int		fboxcheck(char grid[9][9], int startrow, int startcol)
{
	int row;
	int col;
	int i;

	i = 1;
	row = 0;
	col = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			i ^= (grid[row + startrow][col + startcol] - '0');
			col++;
		}
		row++;
	}
	if (i == 0)
		return (1);
	else
		return (0);
}

int		finalcheck(char grid[9][9])
{
	int i;
	int j;
	int k;
	int ans;

	ans = 1;
	i = 0;
	while (i < 9)
	{
		ans *= frowcheck(grid, i);
		ans *= fcolcheck(grid, i);
		i++;
	}
	j = 0;
	k = 0;
	while (j < 7)
	{
		while (k < 7)
		{
			ans *= fboxcheck(grid, j, k);
			k += 3;
		}
		j += 3;
	}
	return (ans);
}
