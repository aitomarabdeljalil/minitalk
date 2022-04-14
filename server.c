/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:53:00 by aait-oma          #+#    #+#             */
/*   Updated: 2022/03/24 17:30:39 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void	handler_sig(int sig, siginfo_t *info, void *nothing)
{
	static int	x = 0;
	static char	c = 0;
	static int	pid = 0;
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
		ft_putchar_fd(c, 1);
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
