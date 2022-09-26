/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:14:23 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/04 00:18:04 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	if (c == 0)
		return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	num_words;

	num_words = 0;
	while (*str)
	{
		if (!is_separator(*str, charset) && is_separator(*(str + 1), charset))
			num_words++;
		str++;
	}
	return (num_words);
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

void	save_word(char	**split, char	*str, char	*charset)
{
	int	word_idx;
	int	i;

	word_idx = 0;
	while (*str)
	{
		if (is_separator(*str, charset))
			str++;
		else
		{
			i = 0;
			while (!is_separator(str[i], charset))
				i++;
			split[word_idx] = (char *) malloc(sizeof(char) * (i + 1));
			if (split[word_idx] == NULL)
				return ;
			ft_strncpy(split[word_idx], str, i);
			word_idx += 1;
			str += i;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**splitted;
	int		num_words;

	num_words = count_words(str, charset);
	splitted = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (splitted == NULL)
		return (NULL);
	splitted[num_words] = NULL;
	save_word(splitted, str, charset);
	return (splitted);
}
