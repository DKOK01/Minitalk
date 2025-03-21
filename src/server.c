/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:52:23 by aysadeq           #+#    #+#             */
/*   Updated: 2025/03/21 21:44:52 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	g_char = 0;

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit_count = 0;
	static int	pid = 0;

	(void)context;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		bit_count = 0;
		g_char = 0;
	}
	g_char = (g_char << 1) | (signum == SIGUSR2);
	bit_count++;
	if (bit_count == 8)
	{
		if (g_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &g_char, 1);
		g_char = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
