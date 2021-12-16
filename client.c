/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:58:46 by a1                #+#    #+#             */
/*   Updated: 2021/12/16 17:36:48 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signal, siginfo_t *siginfo, void *context)
{
	(void) context;
	if (signal == SIGUSR1)
		ft_printf("I got signal from PID %d\n", siginfo->si_pid);
}

static void	ft_kill(int pid, char c)
{
	int	i;

	i = 128;
	while (i)
	{
		if (c & i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i /= 2;
		usleep(900);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sigac;
	char				*str;

	if (argc != 3)
		return (1);
	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &sigac, NULL) < 0)
		ft_printf("Sigaction error");
	if (sigaction(SIGUSR2, &sigac, NULL) < 0)
		ft_printf("Sigaction error");
	str = argv[2];
	while (*str)
		ft_kill(ft_atoi(*(argv + 1)), *str++);
	return (0);
}
