/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:11:59 by juwkim            #+#    #+#             */
/*   Updated: 2022/04/29 02:32:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long		i;
	const long long	n = (long long) nb;

	i = 5;
	if (n < 2)
		return (0);
	else if (n < 4)
		return (1);
	else if (((n % 2 == 0) || (n % 3 == 0)))
		return (0);
	else
	{
		while (i * i <= n)
		{
			if ((n % i == 0) || (n % (i + 2) == 0))
				return (0);
			i += 6;
		}
	}
	return (1);
}
