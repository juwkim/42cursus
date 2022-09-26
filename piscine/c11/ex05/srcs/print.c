/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:19:02 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/05 12:20:20 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "print.h"

int	ft_strlen(char *str)
{
	const char	*p = str;

	while (*str)
		str++;
	return (str - p);
}

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	ft_put_str(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_put_nbr(int num)
{
	if (num == -2147483648)
	{
		ft_put_str("-2147483648");
	}
	else if (num < 0)
	{
		ft_put_char('-');
		ft_put_nbr(-num);
	}
	else
	{
		if (num >= 10)
			ft_put_nbr(num / 10);
		ft_put_char(num % 10 + '0');
	}
}
