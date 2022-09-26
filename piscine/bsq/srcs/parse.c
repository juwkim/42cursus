/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:19:09 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/05 10:39:03 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "t_map.h"
#include "t_array.h"
#include "solve.h"

int	ft_atoi(char *str, int len)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (i < len)
	{
		if (!('0' <= *str && *str <= '9'))
			return (0);
		num = num * 10 + *str++ - '0';
		i++;
	}
	return (num);
}

int	parse_initial_line(int fd, t_map *map)
{
	char	cache[20];
	int		len;

	len = 0;
	while (read(fd, cache + len, 1) == 1)
	{
		if (cache[len] == '\n')
			break ;
		if (len >= 15)
			return (0);
		len++;
	}
	if (len < 4)
		return (0);
	map->rows = ft_atoi(cache, len - 3);
	if (map->rows < 1 || cache[len - 1] == cache[len - 2]
		|| cache[len - 1] == cache[len - 3] || cache[len - 2] == cache[len - 3])
		return (0);
	map->c_empty = cache[len - 3];
	map->c_obstacle = cache[len - 2];
	map->c_full = cache[len - 1];
	return (1);
}

int	parse(int fd, t_map *map, t_array *array)
{	
	char	c;
	int		row_idx;

	row_idx = 0;
	while (read(fd, &c, 1) == 1)
	{
		if (c == '\n')
		{
			if ((array->len != map->cols && map->cols != 0) || array->len == 0)
				return (0);
			map->cols = array->len;
			append_map(map, array, row_idx++);
			clear_arrary(array);
			if (row_idx == map->rows)
				return (1);
			continue ;
		}
		if (c != map->c_empty && c != map->c_obstacle)
			return (0);
		append_array(array, c);
	}
	if (row_idx != map->rows)
		return (0);
	return (1);
}

int	parse_n_solve(int fd)
{
	t_map	*map;
	t_array	*array;

	map = init_map();
	array = init_array();
	if (parse_initial_line(fd, map) == 0)
		return (0);
	if (set_map(map) == 0)
		return (0);
	if (parse(fd, map, array) == 0)
		return (0);
	solve(map);
	free_map(map);
	free(map);
	free_array(array);
	free(array);
	return (1);
}
