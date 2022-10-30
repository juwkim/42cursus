/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:42:42 by juwkim            #+#    #+#             */
/*   Updated: 2022/10/30 17:40:28 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../includes/minitalk.h"

static void	ft_server_handler(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	mask = 1;
	const int	end = 1 << CHAR_BIT;

	(void)context;
	if (sig == SIGUSR1)
		c |= mask;
	mask <<= 1;
	if (mask == end)
	{
		if (c == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR1);
		}
		else
			ft_printf("%c", c);
		c = 0;
		mask = 1;
	}
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("Starting Minitalk server...\n");
	ft_printf("Process ID: %d\n", getpid());
	ft_printf("____________________________\n");
	act.sa_sigaction = ft_server_handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
