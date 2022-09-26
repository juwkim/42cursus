/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjpar <hyunjpar@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:25:02 by hyunjpar          #+#    #+#             */
/*   Updated: 2022/05/04 23:13:13 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	up;
	int	down;

	i = 0;
	up = 0;
	down = 0;
	while (i < length - 1)
	{
		up += (f(tab[i], tab[i + 1]) <= 0);
		down += (f(tab[i], tab[i + 1]) >= 0);
		i++;
	}
	return ((up == i) || (down == i));
}
