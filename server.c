/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:54:01 by a1                #+#    #+#             */
/*   Updated: 2021/12/16 17:14:32 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signal, siginfo_t *siginfo, void *context)
{
	static int				index = 0;
	static unsigned char	c = 0;

	(void) context;
	(void) siginfo;
	c |= (signal == SIGUSR1);
	if (++index == 8)
	{
		ft_printf("%c", c);
		index = 0;
		c = 0;
	}
	else
		c <<= 1;
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sigac;

	ft_printf("Server PID: %d\n", getpid());
	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &sigac, NULL) < 0)
		ft_printf("Sigaction error");
	if (sigaction(SIGUSR2, &sigac, NULL) < 0)
		ft_printf("Sigaction error");
	while (1)
		pause();
	return (0);
}
