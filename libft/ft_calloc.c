/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:43:12 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/03 14:35:34 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
    void *p;

    p = NULL;
    if (count == 0 || size == 0)
        return (p);
    p = malloc(count * size);
    if (p != NULL)
    {
        ft_bzero(p, count * size);
    }
    return (p);
}