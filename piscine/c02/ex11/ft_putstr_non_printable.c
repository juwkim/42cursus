/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:11:11 by juwkim            #+#    #+#             */
/*   Updated: 2022/04/25 10:37:10 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_printable(char c)
{
	return ((32 <= c) && (c <= 127));
}

void	ft_putstr_non_printable(char *str)
{
	const char		*base16;
	char			buf[3];
	unsigned char	c;

	buf[0] = '\\';
	base16 = "0123456789abcdef";
	while (*str)
	{
		if (is_printable(*str))
			write(1, str, 1);
		else
		{
			c = (unsigned char)*str;
			buf[1] = base16[c >> 4];
			buf[2] = base16[c & 15];
			write(1, buf, 3);
		}
		str++;
	}
}
