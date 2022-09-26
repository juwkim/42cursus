/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:35:19 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/04 19:36:12 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strdup(char *src)
{
	long long	len;
	char		*ret;

	len = 0;
	while (src[len])
		++len;
	ret = (char *) malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	ret[len] = 0;
	while (--len >= 0)
		ret[len] = src[len];
	return (ret);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*av_arr;
	int				i;

	av_arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (av_arr == NULL)
		return (NULL);
	i = 0;
	while (av[i] != 0 && i < ac)
	{
		av_arr[i].size = ft_strlen(av[i]);
		av_arr[i].str = av[i];
		av_arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	av_arr[i].size = 0;
	av_arr[i].str = 0;
	av_arr[i].copy = 0;
	return (av_arr);
}
