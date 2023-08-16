/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:46:50 by ldeville          #+#    #+#             */
/*   Updated: 2023/04/18 17:19:00 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include "ft_printf/ft_printf.h"

char	*g_str;

void	ft_addchar(char c)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!g_str)
	{
		g_str = malloc(sizeof(char) * 1);
		bzero(g_str, 1);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(g_str) + 2));
	while (g_str[i])
	{
		tmp[i] = g_str[i];
		i++;
	}
	tmp[i++] = c;
	tmp[i] = 0;
	free(g_str);
	g_str = tmp;
}

void	ft_sendstr(void)
{
	ft_putstr_fd(g_str, 1);
	ft_putchar_fd('\n', 1);
	free(g_str);
	g_str = 0;
}

static void	received(int sig, siginfo_t *infos, void *context)
{
	static int		i = 0;
	static pid_t	client = 0;
	static char		c = 0;

	(void)context;
	if (!client)
		client = infos->si_pid;
	c <<= 1;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			ft_sendstr();
			kill(client, SIGUSR2);
			usleep(100);
			client = 0;
			return ;
		}
		ft_addchar(c);
		c = 0;
	}
	kill(client, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sig;

	g_str = 0;
	ft_printf("Server PID : %i\n", getpid());
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = received;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		usleep(100);
	return (0);
}
