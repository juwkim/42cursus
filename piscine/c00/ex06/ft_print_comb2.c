/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:18:37 by juwkim            #+#    #+#             */
/*   Updated: 2022/04/17 15:16:28 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		first;
	int		second;
	char	str[7];

	first = 0;
	str[2] = ' ';
	str[5] = ',';
	str[6] = ' ';
	while (first < 98)
	{
		str[0] = first / 10 + '0';
		str[1] = first % 10 + '0';
		second = first + 1;
		while (second < 100)
		{
			str[3] = second / 10 + '0';
			str[4] = second % 10 + '0';
			write(1, str, 7);
			second++;
		}
		first++;
	}
	write(1, "98 99", 5);
}
