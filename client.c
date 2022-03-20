/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:34:44 by aait-oma          #+#    #+#             */
/*   Updated: 2022/03/20 17:00:17 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

int	main(int ac, char **av)
{
	int	sid;
	int	i;
	int	bit;

	i = 0;
	if (ac != 3 && printf("ac != 3"))
		exit(1);
	sid = ft_atoi(av[1]);
	if (sid <= 0)
		exit(1);
	while (av[2][i])
	{
		bit = 0;
		while (bit < 8)
		{
			if ((av[2][i] >> bit) & 1)
				kill(sid, SIGUSR1);
			else
				kill(sid, SIGUSR2);
			usleep(500);
			bit++;
		}
		i++;
	}
	return (0);
}
