/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:54:46 by juwkim            #+#    #+#             */
/*   Updated: 2022/10/12 18:55:19 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_skip_atoi(const char **s)
{
	int	num;

	num = 0;
	while ('0' <= **s && **s <= '9')
		num = num * 10 + *((*s)++) - '0';
	return (num);
}

int	ft_strlen(const char *s)
{
	const char	*ptr = s;

	while (*ptr)
		ptr++;
	return (ptr - s);
}

int	ft_itoa(char *buf, unsigned long num, int base, int lower)
{
	static const char	digits[16] = "0123456789ABCDEF";
	char				*ptr;

	ptr = buf;
	while (1)
	{
		*ptr++ = digits[num % base] | lower;
		num /= base;
		if (num == 0)
			break ;
	}
	reverse(buf, ptr);
	return (ptr - buf);
}

void	reverse(char *buf, char *end)
{
	char	tmp;

	end--;
	while (buf < end)
	{
		tmp = *buf;
		*buf = *end;
		*end = tmp;
		buf++;
		end--;
	}
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
