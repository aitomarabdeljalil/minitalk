/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:03:53 by aait-oma          #+#    #+#             */
/*   Updated: 2022/03/16 00:03:53 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void	print(char c, siginfo_t *info)
{
	if (c == 0)
		kill(info->si_pid, SIGUSR1);
	ft_putchar_fd(c, 1);
}

void	handler_sig(int sig, siginfo_t *info, void *nothing)
{
	static int	x;
	static char	c;
	static int	pid;
	char		shift;

	(void)nothing;
	if (info->si_pid != pid)
	{
		x = 0;
		c = 0;
		pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		shift = 1 << x;
	else
		shift = 0;
	c += shift;
	if (x == 7)
	{
		print(c, info);
		x = 0;
		c = 0;
	}
	else
		x++;
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler_sig;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1337)
		pause();
	return (0);
}
