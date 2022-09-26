/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_array.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:22:25 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/05 09:22:26 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ARRAY_H
# define T_ARRAY_H

typedef struct s_array
{
	char	*data;
	int		capacity;
	int		len;
}	t_array;

t_array	*init_array(void);
int		append_array(t_array *array, char val);
void	clear_arrary(t_array	*array);
void	free_array(t_array *array);

#endif
