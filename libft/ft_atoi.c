/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:22:15 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/03 14:37:46 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

int ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	ng;

	i = 0;
	res = 0;
	ng = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			ng ++;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		i++;
	}
	if (ng == 1)
		res *= -1;
	return (res);
}