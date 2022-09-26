/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:05:39 by juwkim            #+#    #+#             */
/*   Updated: 2022/04/25 13:49:50 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	to_lower(char *c)
{
	*c |= 0b00100000;
}

void	to_upper(char *c)
{
	*c &= 0b01011111;
}

int	is_alpha(char c)
{
	to_lower(&c);
	return ((('a' <= c) && (c <= 'z')));
}

int	is_alnum(char c)
{
	return ((is_alpha(c) || (('0' <= c) && (c <= '9'))));
}

char	*ft_strcapitalize(char *str)
{
	char	*p;
	int		b_is_alnum;

	p = str;
	b_is_alnum = 0;
	while (*p)
	{
		if (is_alpha(*p))
		{
			if (b_is_alnum)
				to_lower(p);
			else
				to_upper(p);
		}
		b_is_alnum = is_alnum(*p);
		p++;
	}
	return (str);
}
