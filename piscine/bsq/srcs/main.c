/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:10:03 by juwkim            #+#    #+#             */
/*   Updated: 2022/05/05 09:12:31 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "t_map.h"
#include "t_array.h"
#include "solve.h"
#include "parse.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		res;
	char	**end;

	end = argv + argc;
	if (argc == 1)
	{
		if (parse_n_solve(0) == 0)
			write(2, "map error\n", 10);
	}
	else
	{
		while (argv < end)
		{
			fd = open(*(++argv), O_RDONLY);
			if (fd == -1)
				return (0);
			res = parse_n_solve(fd);
			if (res == 0)
				write(2, "map error\n", 10);
			close(fd);
			write(1, "\n", 1);
		}
	}
	return (0);
}
