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

#include "libft/libft.h"
#include "minitalk.h"

void	initialize(int *x, char *c, int *pid, int ipid)
{
	x = 0;
	c = 0;
	*pid = ipid;
}

void	handler_sig(int sig, siginfo_t *info, void *vv)
{
	static int	x = 0;
	static char	c = 0;
	static int	pid = 0;
	char		shift;

	(void)vv;
	if (info->si_pid != pid)
		initialize(&x, &c, &pid, info->si_pid);
	if (sig == SIGUSR1)
		shift = 1 << x;
	else
		shift = 0;
	c += shift;
	if (x == 7)
	{
		if (c == 0)
			kill(info->si_pid, SIGUSR1);
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
	if (pid == -1)
		exit(1);
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
