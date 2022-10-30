/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 02:01:30 by juwkim            #+#    #+#             */
/*   Updated: 2022/10/30 16:58:05 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_space(int c)
{
	return ((c == ' ') || ((9 <= c) && (c <= 13)));
}

int	ft_is_numeric(char c)
{
	return (('0' <= c) && (c <= '9'));
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str && ft_is_space(*str))
		str++;
	while (*str)
	{
		if (*str == '-')
			sign *= -1;
		else if (*str != '+')
			break ;
		str++;
	}
	while (*str && ft_is_numeric(*str))
		res = res * 10 + *str++ - '0';
	return (sign * res);
}
