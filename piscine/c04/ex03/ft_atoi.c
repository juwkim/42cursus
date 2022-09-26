/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:55:29 by juwkim            #+#    #+#             */
/*   Updated: 2022/04/27 10:54:11 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(int c)
{
	return ((c == ' ') || ((9 <= c) && (c <= 13)));
}

int	ft_is_numeric(char c)
{
	return (('0' <= c) && (c <= '9'));
}

int	ft_atoi(char *str)
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
