/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisulee <jisulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:19:18 by jisulee           #+#    #+#             */
/*   Updated: 2022/04/24 21:56:38 by jisulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str);
int		is_all_space(char *str);
int		is_all_one2four(char *str);

int	check_valid_input(char *str)
{
	if (ft_strlen(str) != 31)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	if (!is_all_space(str))
	{
		write (1, "Error\n", 6);
		return (0);
	}
	if (!is_all_one2four(str))
	{
		write (1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	check_valid_allocate(char *mem)
{
	if (mem == NULL)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}
