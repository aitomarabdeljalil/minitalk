/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 21:01:12 by aait-oma          #+#    #+#             */
/*   Updated: 2021/06/25 09:26:52 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int	i;
	int	thisletter;

	i = 0;
	while (i < 26)
	{
		thisletter = 'a' + i;
		write(1, &thisletter, 1);
		i++;
	}
}
