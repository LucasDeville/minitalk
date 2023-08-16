/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:30:33 by ldeville          #+#    #+#             */
/*   Updated: 2023/04/18 17:19:08 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"

int	g_signal;

static void	received(int sig)
{
	if (sig == SIGUSR1)
		g_signal = 1;
	else
	{
		ft_printf("Message reçu !\n");
		exit(0);
	}
}

static void	send_end(int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		while (!g_signal)
			usleep(100);
		g_signal = 0;
	}
}

static void	send(int pid, char *str)
{
	int		i;
	char	c;

	ft_printf("Sending : %s\n", str);
	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c & (1 << i))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			while (!g_signal)
				usleep(100);
			g_signal = 0;
		}
	}
	send_end(pid);
}

int	main(int argc, char **argv)
{
	if (argc != 3 || argv[2] == 0)
	{
		ft_printf("Please type : ./client <server PID> <message>\n");
		return (-1);
	}
	g_signal = 0;
	signal(SIGUSR1, received);
	signal(SIGUSR2, received);
	send(ft_atoi(argv[1]), argv[2]);
	while (1)
		usleep(100);
	return (0);
}
