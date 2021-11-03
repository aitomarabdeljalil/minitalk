/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:37:47 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/03 08:45:29 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    int len;

    len = (int) (ft_strlen(s) - 1);
    while (s[len] != (char) c && len >= 0)
        len--;
    if (len >= 0)
        return ((char *)(s + len));
    return (NULL);
}