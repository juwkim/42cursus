/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:22:12 by juwkim            #+#    #+#             */
/*   Updated: 2022/04/29 02:36:31 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int n)
{
	long long		i;
	const long long	nb = (long long) n;

	i = 5;
	if (nb < 2)
		return (0);
	else if (nb < 4)
		return (1);
	else if ((nb % 2 == 0) || (nb % 3 == 0))
		return (0);
	else
	{
		while (i * i <= nb)
		{
			if ((nb % i == 0) || (nb % (i + 2) == 0))
				return (0);
			i += 6;
		}
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (!is_prime(nb))
		nb++;
	return (nb);
}
