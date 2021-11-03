/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:01:17 by aait-oma          #+#    #+#             */
/*   Updated: 2021/06/27 14:52:59 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putdig(int d)
{
	char	dig;

	dig = d + '0';
	write(1, &dig, 1);
}

void	ft_putnbr(int n)
{
	if (n <= -10)
	{
		ft_putnbr(n / 10);
		ft_putdig(-(n % -10));
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putdig(-n);
	}	
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putdig(n % 10);
	}
	else if (n >= 0)
	{
		ft_putdig(n);
	}
}
