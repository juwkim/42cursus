/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:08:39 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/23 14:08:41 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_duplicate(char *map, int depth)
{
	int	x_start;
	int	y_start;
	int	idx;

	x_start = depth % 4;
	y_start = depth - x_start;
	idx = 0;
	while (x_start + idx < 16)
	{
		if (x_start + idx != depth && map[depth] == map[x_start + idx])
			return (1);
		idx += 4;
	}
	idx = 0;
	while (idx < 4)
	{
		if (y_start + idx != depth && map[depth] == map[y_start + idx])
			return (1);
		idx++;
	}
	return (0);
}

int	ft_cnt_col_up(char *map, int depth)
{
	int		idx;
	int		x_start;
	int		count;
	char	max;

	idx = 0;
	x_start = depth % 4;
	count = 0;
	max = '0';
	while (x_start + idx <= 15)
	{
		if (max < map[x_start + idx])
		{
			max = map[x_start + idx];
			count++;
		}
		idx += 4;
	}
	return (count);
}

int	ft_cnt_col_down(char *map, int depth)
{
	int		idx;
	int		x_end;
	int		count;
	char	max;

	idx = 0;
	x_end = depth % 4 + 12;
	count = 0;
	max = '0';
	while (x_end + idx >= 0)
	{
		if (max < map[x_end + idx])
		{
			max = map[x_end + idx];
			count++;
		}
		idx -= 4;
	}
	return (count);
}

int	ft_cnt_row_left(char *map, int depth)
{
	int		idx;
	int		y_start;
	int		count;
	char	max;

	idx = 0;
	y_start = (depth / 4) * 4;
	count = 0;
	max = '0';
	while (idx <= 3)
	{
		if (max < map[idx + y_start])
		{
			max = map[idx + y_start];
			count++;
		}
		idx++;
	}
	return (count);
}

int	ft_cnt_row_right(char *map, int depth)
{
	int		idx;
	int		y_end;
	int		count;
	char	max;

	idx = 0;
	y_end = (depth / 4) * 4 + 3;
	count = 0;
	max = '0';
	while (y_end + idx >= 0)
	{
		if (max < map[idx + y_end])
		{
			max = map[idx + y_end];
			count++;
		}
		idx--;
	}
	return (count);
}
