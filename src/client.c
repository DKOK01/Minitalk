/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:09:08 by aysadeq           #+#    #+#             */
/*   Updated: 2025/03/22 21:02:10 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

bool	g_state;

void	signal_handler(int signum)
{
	g_state = true;
	(void)signum;
}

int	is_valid_pid(char *pid)
{
	int	i;

	i = 0;
	if (!pid || !pid[0])
		return (0);
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			return (0);
		i++;
	}
	return (1);
}

void	send_char(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_state = false;
		if ((c >> bit) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		bit--;
		while (!g_state)
			;
		usleep(50);
	}
}

void	send_message(pid_t pid, char *message)
{
	int		i;

	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [PID] [Message]\n");
		return (0);
	}
	if (!is_valid_pid(argv[1]))
	{
		ft_printf("Invalid PID\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID\n");
		return (0);
	}
	signal(SIGUSR1, signal_handler);
	send_message(pid, argv[2]);
	return (0);
}
