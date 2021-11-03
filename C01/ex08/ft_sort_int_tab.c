/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 12:09:46 by aait-oma          #+#    #+#             */
/*   Updated: 2021/06/27 12:09:53 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	swapvar;

	swapvar = *a;
	*a = *b;
	*b = swapvar;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	min;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i;
		min = tab[i];
		while (j < size)
		{
			if (min > tab[j])
			{
				min = tab[j];
				ft_swap(&tab[i], &tab[j]);
			}
			j++;
		}
		i++;
	}
}
