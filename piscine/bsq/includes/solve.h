/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:22:14 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/05 09:22:16 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H
# include "t_map.h"

int		min(int a, int b, int c);
void	draw_map(int rows, int cols, int size, t_map *digit_map);
void	solve(t_map *digit_map);
#endif
