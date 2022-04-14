/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:34:44 by aait-oma          #+#    #+#             */
/*   Updated: 2022/03/23 12:28:38 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void	ft_send(char *str, int sid)
{
	size_t	i;
	int		bit;

	i = 0;
	while (i <= ft_strlen(str))
	{
		bit = 0;
		while (bit < 8)
		{
			if ((str[i] >> bit) & 1)
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
}

int	main(int ac, char **av)
{
	int	sid;

	if (ac != 3)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	sid = ft_atoi(av[1]);
	if (sid <= 0)
		exit(1);
	ft_send(av[2], sid);
	return (0);
}
