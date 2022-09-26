/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:22:33 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/05 09:22:34 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_H
# define T_MAP_H

# include "t_array.h"

typedef struct s_map {
	int		rows;
	int		cols;
	int		**data;
	char	c_empty;
	char	c_obstacle;
	char	c_full;
}	t_map;

t_map	*init_map(void);
int		set_map(t_map *map);
int		append_map(t_map *map, t_array *array, int row_idx_to_append);
void	free_map(t_map *map);
void	print_map(t_map *map);

#endif
