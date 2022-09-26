/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:39:32 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/06 02:15:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgen.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "cat.h"

void	put_str_to_stderr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	show_error(char *name, char *file)
{
	if (errno == 0)
		return ;
	put_str_to_stderr(basename(name));
	put_str_to_stderr(": ");
	put_str_to_stderr(file);
	put_str_to_stderr(": ");
	put_str_to_stderr(strerror(errno));
	put_str_to_stderr("\n");
	errno = 0;
}

void	do_cat(char *name, char *file, int fd)
{
	int		byte_read;
	char	buf[MAXSIZE];

	while (1)
	{	
		byte_read = read(fd, buf, MAXSIZE);
		if (byte_read == 0)
			break ;
		if (errno != 0)
		{
			show_error(name, file);
			break ;
		}
		write(1, buf, byte_read);
	}
	if (fd > 2)
		close(fd);
}

void	stdin_loop(void)
{
	do_cat(NULL, NULL, 0);
}

int	cat(char **files, int file_count)
{
	int		fd;
	int		idx;
	char	*path;

	path = files[0];
	idx = 1;
	while (idx <= file_count)
	{
		fd = open(files[idx], O_RDONLY);
		if (fd < 0)
			show_error(path, files[idx]);
		else
			do_cat(path, files[idx], fd);
		idx++;
	}
	return (0);
}
