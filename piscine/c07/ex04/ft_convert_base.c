/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:14:03 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/04 00:16:12 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_valid_base(char	*base)
{
	int		len;
	char	cache[256];

	len = -1;
	while (++len < 256)
		cache[len] = 0;
	len = -1;
	while (base[++len])
	{
		if (cache[(int)base[len]])
			return (0);
		cache[(int)base[len]] = 1;
		if (base[len] == '-' || base[len] == '+'
			|| base[len] == ' ' || base[len] == '\n'
			|| base[len] == '\t' || base[len] == '\v'
			|| base[len] == '\f' || base[len] == '\r')
			return (0);
	}
	return (len);
}

int	where_is_char(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i += 1;
	}
	return (-1);
}

long long	ib2ll(char *nbr, char *ibase, int ibase_len)
{
	long long	num;
	int			tmp;

	num = 0;
	while (*nbr)
	{
		tmp = where_is_char(*nbr, ibase);
		if (tmp == -1)
			break ;
		num *= ibase_len;
		num += tmp;
		nbr++;
	}
	return (num);
}

char	*ll2ob(long long num, int sign, char *obase, int obase_len)
{
	int			len;
	long long	tmp;
	char		*str;

	len = ((num == 0) || (sign == -1));
	tmp = num;
	while (tmp)
	{
		len += 1;
		tmp /= obase_len;
	}
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = 0;
	str[0] = '-';
	while (1)
	{
		str[--len] = obase[num % obase_len];
		num /= obase_len;
		if (num == 0)
			break ;
	}
	return (str);
}

char	*ft_convert_base(char	*nbr, char	*base_from, char	*base_to)
{
	int			ib_len;
	int			ob_len;
	int			s;

	ib_len = is_valid_base(base_from);
	ob_len = is_valid_base(base_to);
	if (ib_len < 2 || ob_len < 2)
		return (0);
	s = 1;
	while (*nbr == '\t' || *nbr == '\n' || *nbr == '\v'
		|| *nbr == '\f' || *nbr == '\r' || *nbr == ' ')
		++nbr;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*(nbr) == '-')
			s *= -1;
		nbr++;
	}
	return (ll2ob(ib2ll(nbr, base_from, ib_len), s, base_to, ob_len));
}
