/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:27:46 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/06 02:14:36 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "main.h"

int	display_file(char *path)
{
	int		fd;
	int		byte_read;
	char	buf[MAXSIZE];

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		byte_read = read(fd, buf, MAXSIZE);
		if (byte_read <= 0)
			break ;
		write(1, buf, byte_read);
	}
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	int	res;

	if (argc < 2)
	{
		write(2, MSG_ERR_NO_FILE, 19);
		return (1);
	}
	if (argc > 2)
	{
		write(2, MSG_ERR_TOO_MANY_ARGS, 20);
		return (2);
	}
	res = display_file(argv[1]);
	if (res == 0)
	{
		write(2, MSG_ERR_CANNOT_READ, 18);
		return (3);
	}
	return (0);
}
