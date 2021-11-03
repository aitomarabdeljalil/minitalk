/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:02:40 by aait-oma          #+#    #+#             */
/*   Updated: 2021/06/27 15:14:28 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putfig(int f)
{
	char	cur_f;

	cur_f = f + '0';
	write(1, &cur_f, 1);
}

void	ft_show(int x, int y)
{
	ft_putfig(x / 10);
	ft_putfig(x % 10);
	write(1, " ", 1);
	ft_putfig(y / 10);
	ft_putfig(y % 10);
	if (x != 98 || y != 99)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_show(a, b);
			b++;
		}
		a++;
	}
}
