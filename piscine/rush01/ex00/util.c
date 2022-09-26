/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisulee <jisulee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:13:06 by jisulee           #+#    #+#             */
/*   Updated: 2022/04/24 21:14:24 by jisulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	char	*p;

	p = str;
	while (*p++)
		;
	return (p - str - 1);
}

int	is_all_space(char *str)
{
	int	idx;

	idx = 1;
	while (idx < 30)
	{	
		if (str[idx] != ' ')
			return (0);
		idx += 2;
	}
	return (1);
}

int	is_all_one2four(char *str)
{
	int	idx;

	while (idx < 31)
	{
		if (!('1' <= str[idx] && str[idx] <= '4'))
			return (0);
		idx += 2;
	}
	return (1);
}

void	ft_split(char *str, char *input)
{
	int	idx;

	idx = 0;
	while (idx < 31)
	{
		input[idx / 2] = str[idx];
		idx += 2;
	}
	input[16] = '\0';
}

void	ft_init_map(char *map)
{
	int	idx;

	idx = 0;
	while (idx < 16)
	{
		map[idx] = '0';
		idx++;
	}
	map[idx] = '\0';
}
