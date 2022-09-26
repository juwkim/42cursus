/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:15:55 by juwkim            #+#    #+#             */
/*   Updated: 2022/04/28 22:09:56 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_base(char c, char *base)
{
	while (*base)
	{
		if (c == *base++)
			return (1);
	}
	return (0);
}

int	my_ft_strlen(char *str)
{
	const char	*p = str;

	while (*str)
		str++;
	return (str - p);
}

int	my_ft_is_valid_base(char *base)
{
	int		idx;
	char	table[127];
	int		base_len;

	base_len = my_ft_strlen(base);
	if (base_len < 2)
		return (0);
	idx = 0;
	while (idx < 127)
		table[idx++] = 0;
	while (*base)
		table[(int) *base++] += 1;
	if (table['+'] + table['-'] + table[' '])
		return (0);
	idx = 0;
	while (idx < 127)
	{
		if (table[idx++] > 1)
			return (0);
	}
	return (1);
}

int	init(char **str, char *base, int *sign)
{
	if (!my_ft_is_valid_base(base))
		return (0);
	while (**str && ((**str == ' ') || ((9 <= **str) && (**str <= 13))))
		(*str)++;
	while (**str)
	{
		if (**str == '-')
			*sign *= -1;
		else if (**str != '+')
			break ;
		(*str)++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	sign;
	int	idx;
	int	base_len;
	int	table[127];

	res = 0;
	sign = 1;
	idx = 0;
	base_len = my_ft_strlen(base);
	if (!init(&str, base, &sign))
		return (0);
	while (idx < base_len)
	{
		table[(int) base[idx]] = idx;
		idx++;
	}
	while (*str && ft_is_base(*str, base))
		res = res * base_len + table[(int) *str++];
	return (sign * res);
}
