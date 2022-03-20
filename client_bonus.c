/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:05:18 by aait-oma          #+#    #+#             */
/*   Updated: 2022/03/19 21:05:18 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void	handler(int sig)
{
	sig = 0;
	ft_putendl_fd("received", 1);
	return ;
}

int	main(int ac, char **av)
{
	int		sid;
	size_t	i;
	int		bit;

	i = 0;
	if (ac != 3 && printf("Error\n"))
		exit(1);
	sid = ft_atoi(av[1]);
	signal(SIGUSR1, &handler);
	if (sid <= 0)
		exit(1);
	while (i <= ft_strlen(av[2]))
	{
		bit = 0;
		while (bit < 8)
		{
			if ((av[2][i] >> bit) & 1)
			{
				if (kill(sid, SIGUSR1))
					exit(EXIT_FAILURE);
			}
			else
				kill(sid, SIGUSR2);
			usleep(500);
			bit++;
		}
		i++;
	}
	return (0);
}
