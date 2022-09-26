/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:15:37 by ecaceres          #+#    #+#             */
/*   Updated: 2022/05/05 12:18:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"
#include "operation.h"
#include "print.h"

char	ft_find_operator(char *str)
{
	if (ft_strlen(str) != 1)
		return (-1);
	return (str[0]);
}

int	ft_is_valid_operation(int num, char operator)
{
	if (num == 0)
	{
		if (operator == '/')
		{
			ft_put_str("Stop : division by zero\n");
			return (0);
		}
		if (operator == '%')
		{
			ft_put_str("Stop : modulo by zero\n");
			return (0);
		}
	}
	return (1);
}

void	ft_do_operation(int a, int b, char operator)
{
	const char	operators[5] = {'+', '-', '/', '*', '%'};
	static int	(*operations[5])(int, int) = {
		operation_add,
		operation_minus,
		operation_devide,
		operation_multiply,
		operation_modulo
	};
	int			result;
	int			index;

	result = 0;
	index = 0;
	while (index < 5)
	{
		if (operator == operators[index])
		{
			result = (operations[index])(a, b);
			break ;
		}
		index++;
	}
	ft_put_nbr(result);
	ft_put_str("\n");
}

int	main(int argc, char **argv)
{
	int		num1;
	int		num2;
	char	operator;

	if (argc == 4)
	{
		num1 = ft_atoi(argv[1]);
		num2 = ft_atoi(argv[3]);
		operator = ft_find_operator(argv[2]);
		if (ft_is_valid_operation(num2, operator))
			ft_do_operation(num1, num2, operator);
	}
}
