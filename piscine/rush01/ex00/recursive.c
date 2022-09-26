/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:08:21 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/23 14:08:24 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_valid(char *map, int depth);
int	ft_is_ans(char *map, char *input);

void	ft_print_ans(char *map)
{
	int		idx;
	char	str;

	idx = 0;
	while (idx < 16)
	{
		str = map[idx];
		write (1, &str, 1);
		if (idx % 4 != 3)
			write (1, " ", 1);
		else
			write (1, "\n", 1);
		idx++;
	}
}

int	ft_tracking(int depth, char *map, char *input)
{
	int		rtn;
	char	input_num;

	if (depth == 16)
	{
		if (!ft_is_ans(map, input))
		{
			return (0);
		}
		ft_print_ans(map);
		return (1);
	}
	rtn = 0;
	input_num = '1';
	while (input_num <= '4' && rtn == 0)
	{
		map[depth] = input_num;
		if (ft_is_valid(map, depth))
		{
			rtn = ft_tracking(depth + 1, map, input);
		}
		map[depth] = '0';
		input_num++;
	}
	return (rtn);
}
