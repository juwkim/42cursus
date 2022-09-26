/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:16:43 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/05 12:27:42 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"

int	ft_is_numeric(char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_is_space(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	sign = 1;
	while (ft_is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	while (ft_is_numeric(*str))
		result = result * 10 + *str++ - '0';
	return (sign * result);
}
