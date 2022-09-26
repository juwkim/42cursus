/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:13:01 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/05 09:13:40 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_map.h"
#include "t_array.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->rows = 0;
	map->cols = 0;
	map->c_empty = '\0';
	map->c_full = '\0';
	map->c_obstacle = '\0';
	map->data = NULL;
	return (map);
}

int	set_map(t_map *map)
{
	map->data = (int **) malloc(sizeof(int *) * map->rows);
	if (map->data == NULL)
		return (0);
	return (1);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
		free(map->data[i++]);
	free(map->data);
}

int	append_map(t_map *map, t_array *array, int idx)
{
	int	i;

	i = 0;
	map->data[idx] = (int *) malloc(sizeof(int) * map->cols);
	if (map->data[idx] == NULL)
		return (0);
	while (i < map->cols)
	{
		if (array->data[i] == map->c_empty)
			map->data[idx][i] = 1;
		else if (array->data[i] == map->c_obstacle)
			map->data[idx][i] = 0;
		i++;
	}
	return (1);
}
