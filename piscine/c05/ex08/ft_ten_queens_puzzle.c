/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjpar <hyunjpar@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:33:43 by hyunjpar          #+#    #+#             */
/*   Updated: 2022/04/28 19:57:48 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_board(int	*board)
{
	const int	*p = board + 10;

	while (board < p)
		write(1, board++, 1);
	write(1, "\n", 1);
}

int	is_valid(int *board, int idx)
{
	int	row;

	row = 0;
	while (row < idx)
	{
		if (board[row] == board[idx])
			return (0);
		if (board[row] - board[idx] == row - idx)
			return (0);
		if (board[row] - board[idx] == idx - row)
			return (0);
		row++;
	}
	return (1);
}

void	ten_queens_base(int *board, int idx, int *count)
{
	int	pos;

	pos = '0';
	while (pos <= '9')
	{
		board[idx] = pos;
		if (is_valid(board, idx))
		{
			if (idx == 9)
			{
				print_board(board);
				*count += 1;
				return ;
			}
			else
				ten_queens_base(board, idx + 1, count);
		}
		pos++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	ten_queens_base(board, 0, &count);
	return (count);
}
