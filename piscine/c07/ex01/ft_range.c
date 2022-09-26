/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:40:04 by juwkim            #+#    #+#             */
/*   Updated: 2022/04/29 09:40:59 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	*ptr;

	if (min >= max)
		return (NULL);
	res = (int *) malloc(sizeof(int) * (max - min));
	if (res != NULL)
	{
		ptr = res;
		while (min < max)
			*ptr++ = min++;
	}
	return (res);
}
