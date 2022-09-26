/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:22:48 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/05 09:23:36 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "t_map.h"

int	ft_atoi(char *str, int len);
int	parse_initial_line(int fd, t_map *map);
int	parse(int fd, t_map *map, t_array *array);
int	parse_n_solve(int fd);
#endif
