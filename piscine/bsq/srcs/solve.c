/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:13:51 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/05 10:35:35 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "t_map.h"

int	min(int a, int b, int c)
{
	int	min;

	if (a <= b && a <= c)
		min = a;
	else if (b <= c)
		min = b;
	else
		min = c;
	return (min);
}

void	draw_map(int rows, int cols, int size, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (rows - size < i && i <= rows && cols - size < j && j <= cols)
				write(1, &(map->c_full), 1);
			else if (map->data[i][j] == 0)
				write(1, &(map->c_obstacle), 1);
			else
				write(1, &(map->c_empty), 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}

void	find_max_val(int row, int col, t_map *map)
{
	int	max_size;
	int	max_row;
	int	max_col;

	max_size = 0;
	max_row = 0;
	max_col = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->cols)
		{
			if (max_size < map->data[row][col])
			{
				max_size = map->data[row][col];
				max_row = row;
				max_col = col;
			}
			col++;
		}
		row++;
	}
	draw_map(max_row, max_col, max_size, map);
}

void	solve(t_map *map)
{
	int	top;
	int	left;
	int	left_top;
	int	row;
	int	col;

	row = 1;
	while (row < map->rows)
	{
		col = 1;
		while (col < map->cols)
		{
			if (map->data[row][col])
			{
				top = map->data[row - 1][col];
				left = map->data[row][col - 1];
				left_top = map->data[row - 1][col - 1];
				map->data[row][col] += min(top, left, left_top);
			}
			col++;
		}
		row++;
	}
	find_max_val(0, 0, map);
}
