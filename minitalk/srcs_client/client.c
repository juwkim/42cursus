/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:42:47 by juwkim            #+#    #+#             */
/*   Updated: 2022/10/30 16:55:03 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../includes/minitalk.h"

static void	ft_client_handler(int signum)
{
	(void)signum;
	ft_printf("Your message has been delivered well\n");
	exit(0);
}

static void	ft_send(pid_t pid, char *msg)
{
	int			mask;
	const int	end = 1 << CHAR_BIT;

	while (1)
	{
		mask = 1;
		while (mask < end)
		{
			if (*msg & mask)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			mask <<= 1;
			usleep(100);
		}
		if (*msg == '\0')
			break ;
		msg++;
	}
}

int	main(int argc, char *argv[])
{
	const pid_t	pid = ft_atoi(argv[1]);

	if (argc != 3)
	{
		ft_printf("usage: client [server_pid] [message]");
		return (1);
	}
	signal(SIGUSR1, ft_client_handler);
	ft_printf("Sending data to server: %d and message: %s\n", pid, argv[2]);
	ft_send(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
