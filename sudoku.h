#ifndef SUDOKU_H
#define SUDOKU_H
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	sudokuprint(char grid[9][9]);
int		placeable(char grid[9][9], int row, int col, int num);
int		ft_strlen(char *str);
int		ft_checkvalue(char *str);
int		checkargv(char **argv);
int		finalcheck(char grid[9][9]);
#endif
