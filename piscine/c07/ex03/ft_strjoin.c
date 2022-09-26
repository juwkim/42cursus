/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:45:22 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/03 16:26:41 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_strlen1(char *str)
{
	const char	*p = str;

	while (*str)
		str++;
	return (str - p);
}

char	*ft_strcat(char	*dst, char *src)
{
	while (*src)
		*dst++ = *src++;
	return (dst);
}

char	*get_total_len_mem(int size, char **strs, char *sep)
{
	int		cnt;
	int		strs_len;
	char	*str;

	cnt = 0;
	strs_len = 0;
	while (cnt++ < size)
		strs_len += ft_strlen1(*strs++);
	strs_len += ft_max(0, size - 1) * ft_strlen1(sep);
	str = (char *) malloc(sizeof(char) * (strs_len + 1));
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		cnt;
	char	*str;
	char	*ptr;

	str = get_total_len_mem(size, strs, sep);
	if (str != NULL)
	{
		cnt = 0;
		ptr = str;
		while (cnt++ < size - 1)
		{
			ptr = ft_strcat(ptr, *strs++);
			ptr = ft_strcat(ptr, sep);
		}
		if (size)
			ptr = ft_strcat(ptr, *strs);
		*ptr = '\0';
	}
	return (str);
}
