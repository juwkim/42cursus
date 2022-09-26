/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 19:48:24 by juwkim            #+#    #+#             */
/*   Updated: 2022/04/25 10:45:05 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const char	*g_base16 = "0123456789abcdef";

void	print_addr(unsigned long long addr)
{
	char	buf[16];
	char	*ptr;

	ptr = buf + 15;
	while (ptr >= buf)
	{
		*ptr-- = g_base16[addr & 0xF];
		addr >>= 4;
	}
	write(1, buf, 16);
	write(1, ": ", 2);
}

void	print_contents(char *str)
{
	char	buf[40];
	char	*p;
	int		cnt;

	cnt = 16;
	p = buf;
	while (cnt--)
	{
		*p++ = g_base16[*str / 16];
		*p++ = g_base16[*str % 16];
		if (cnt % 2 == 0)
			*p++ = ' ';
		if (*str++ == '\0')
			break ;
	}
	while (cnt-- > 0)
	{
		*p++ = ' ';
		*p++ = ' ';
		if (cnt % 2 == 0)
			*p++ = ' ';
	}
	write(1, buf, 40);
}

int	printable(char c)
{
	return ((32 <= c) && (c <= 127));
}

void	print_str(char *addr)
{
	int	cnt;

	cnt = 0;
	while (cnt < 16)
	{
		if (printable(*addr))
			write(1, addr, 1);
		else
			write(1, ".", 1);
		if (*addr == '\0')
			break ;
		cnt++;
		addr++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			*str;
	unsigned int	cnt;

	cnt = 0;
	str = (char *)addr;
	while (cnt < size)
	{
		print_addr((unsigned long long)str);
		print_contents(str);
		print_str(str);
		str += 16;
		cnt += 16;
	}
	return (addr);
}
