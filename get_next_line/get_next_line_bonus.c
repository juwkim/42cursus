/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 00:46:14 by juwkim            #+#    #+#             */
/*   Updated: 2022/10/05 04:00:52 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_line(char *buf, char **rest, ssize_t size, char **rtn)
{
	int		idx;
	char	*temp;

	buf[size] = '\0';
	idx = ft_strchr(buf, '\n');
	if (idx != -1)
	{
		if (idx < size && buf[idx + 1])
			*rest = ft_substr(buf, idx + 1, size - idx - 1);
		buf[idx + 1] = '\0';
	}
	if (*rtn)
	{
		temp = ft_strjoin(*rtn, buf);
		free(*rtn);
		*rtn = temp;
	}
	else
		*rtn = ft_strdup(buf);
	return (idx != -1);
}

int	check_rest(char **rest, char **rtn)
{
	int		idx;
	int		len;
	char	*temp;

	len = ft_strlen(*rest);
	idx = ft_strchr(*rest, '\n');
	if (-1 < idx && idx < len - 1)
	{
		*rtn = ft_substr(*rest, 0, idx + 1);
		temp = ft_substr(*rest, idx + 1, len - idx - 1);
		free(*rest);
		*rest = temp;
		return (1);
	}
	*rtn = *rest;
	*rest = NULL;
	return (idx != -1);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*buf;
	char		*rtn;
	ssize_t		read_size;

	rtn = NULL;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (rest[fd] && check_rest(rest + fd, &rtn))
		return (rtn);
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0 && get_line(buf, rest + fd, read_size, &rtn) == 0)
		read_size = read(fd, buf, BUFFER_SIZE);
	free(buf);
	return (rtn);
}
