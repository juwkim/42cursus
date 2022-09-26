/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range_.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:41:27 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/03 16:26:32 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int				*p;
	const long long	size = max - min;

	if (size <= 0)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *) malloc(sizeof(int) * size);
	if (*range == NULL)
		return (-1);
	p = *range;
	while (min < max)
		*p++ = min++;
	return (size);
}
