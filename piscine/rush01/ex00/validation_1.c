/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:08:31 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/23 14:08:32 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_duplicate(char *map, int depth);
int	ft_cnt_col_up(char *map, int depth);
int	ft_cnt_col_down(char *map, int depth);
int	ft_cnt_row_left(char *map, int depth);
int	ft_cnt_row_right(char *map, int depth);

int	ft_is_valid(char *map, int depth)
{
	if (ft_is_duplicate(map, depth) == 1)
		return (0);
	return (1);
}

int	ft_is_ans(char *map, char *input)
{
	int	idx;
	int	col_up;
	int	col_down;
	int	row_left;
	int	row_right;

	idx = 0;
	while (idx < 16)
	{
		col_up = input[idx % 4] - '0';
		col_down = input[idx % 4 + 4] - '0';
		row_left = input[idx / 4 + 8] - '0';
		row_right = input[idx / 4 + 12] - '0';
		if (ft_cnt_col_up(map, idx) != col_up)
			return (0);
		if (ft_cnt_col_down(map, idx) != col_down)
			return (0);
		if (ft_cnt_row_left(map, idx) != row_left)
			return (0);
		if (ft_cnt_row_right(map, idx) != row_right)
			return (0);
		idx++;
	}
	return (1);
}
