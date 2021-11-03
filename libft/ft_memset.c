/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:39:10 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/03 16:20:36 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memset(void *b, int c, size_t len)
{
    char *p;
    size_t  i;
    
    p = b;
    i = 0;
    while(len--)
    {
        p[i] = (unsigned char) c;
        i++;
    }
    return (b);
}
