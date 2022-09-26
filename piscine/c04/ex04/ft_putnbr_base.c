/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:09:11 by juwkim            #+#    #+#             */
/*   Updated: 2022/04/27 14:59:39 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	const char	*p = str;

	while (*str)
		str++;
	return (str - p);
}

long long	ft_to_positive_and_print_minus(long long nbr)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	return (nbr);
}

int	ft_is_valid_base(char *base)
{
	int			idx;
	char		table[127];

	if (ft_strlen(base) < 2)
		return (0);
	idx = 0;
	while (idx < 127)
		table[idx++] = 0;
	while (*base)
		table[(int) *base++] += 1;
	if (table['+'] + table['-'])
		return (0);
	idx = 0;
	while (idx < 127)
	{
		if (table[idx++] > 1)
			return (0);
	}
	return (1);
}

void	ft_change_base_and_print(long long nbr, char *base, int base_len)
{
	if (nbr >= base_len)
	{
		ft_change_base_and_print(nbr / base_len, base, base_len);
		write(1, base + nbr % base_len, 1);
	}
	else
		write(1, base + nbr, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	n;

	if (ft_is_valid_base(base))
	{
		n = ft_to_positive_and_print_minus((long long) nbr);
		ft_change_base_and_print(n, base, ft_strlen(base));
	}
}
