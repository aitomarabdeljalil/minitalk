/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:08:22 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/03 09:24:07 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char *t1;
	char *t2;
	int	i;

	*t1 = (char *) s1;
	*t2 = (char *) s2;
	i = 0;
	if (t1 == 0 && t2 == 0)
		return (0);
	while (t1[i] == t2[i])
		i++;
	return (t1[i] - t2[i]);
}