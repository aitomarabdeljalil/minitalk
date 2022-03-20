/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:53:00 by aait-oma          #+#    #+#             */
/*   Updated: 2022/03/20 16:57:19 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

void	handler_sig(int sig, siginfo_t *info, void *nothing)
{
	static int	f;
	static int	x = 0;
	static char	c = 0;
	char		shift;

	if (f == 0)
	{
		kill(info->si_pid, SIGUSR1);
		f++;
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

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	if (pid == -1)
		exit(1);
	ft_putnbr_fd(pid, 1);
	sa.sa_sigaction = &handler_sig;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1337)
		pause();
	return (0);
}
