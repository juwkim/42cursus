/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:11:30 by juwkim            #+#    #+#             */
/*   Updated: 2022/04/17 16:37:30 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn_recur(char arr[], int idx, int n)
{
	int	num;

	num = arr[idx - 1] + 1;
	if (idx == n + 1)
	{
		write(1, arr + 1, n);
		if (arr[1] != 10 - n + '0')
			write(1, ", ", 2);
	}
	else
	{
		while (num < idx - n + 10 + '0')
		{
			arr[idx] = num++;
			ft_print_combn_recur(arr, idx + 1, n);
		}
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	arr[0] = '0' - 1;
	ft_print_combn_recur(arr, 1, n);
}
