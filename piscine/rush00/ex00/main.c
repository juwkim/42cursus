/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungcho <sungcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:48:45 by sungcho           #+#    #+#             */
/*   Updated: 2022/04/19 14:24:50 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

int	ft_atoi(const char *str)
{
	int	num;
	int	minus;

	num = 0;
	minus = 1;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	while ((str) && ('0' <= *str) && (*str <= '9'))
		num = num * 10 + *str++ - '0';
	return (minus * num);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		rush(5, 5);
	else if (argc == 3)
		rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}
