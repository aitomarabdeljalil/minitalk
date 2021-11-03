/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_alphabet.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 21:01:02 by aait-oma          #+#    #+#             */
/*   Updated: 2021/06/27 15:01:45 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int	i;
	int	thisletter;

	i = 0;
	while (i < 26)
	{
		thisletter = 'z' - i;
		write(1, &thisletter, 1);
		i++;
	}
}
