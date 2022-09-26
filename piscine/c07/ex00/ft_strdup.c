/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 05:46:56 by juwkim            #+#    #+#             */
/*   Updated: 2022/04/29 09:39:30 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	const char	*p = str;

	while (*str)
		str++;
	return (str - p);
}

void	ft_strcpy(char *dst, char *src)
{
	const int	src_len = ft_strlen(src);
	int			cnt;

	cnt = 0;
	while (cnt++ < src_len)
		*dst++ = *src++;
	*dst = '\0';
}

char	*ft_strdup(char *src)
{
	char	*dst;

	dst = (char *) malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dst != NULL)
		ft_strcpy(dst, src);
	return (dst);
}
