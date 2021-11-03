/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:38:27 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/03 14:38:31 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t  dl;
	size_t	sl;
	size_t  i;

	dl = ft_strlen(dst);
	sl = ft_strlen((char *)src);
	i = 0;
	if (dstsize == 0 || dstsize <= dl)
		return (sl + dstsize);
	while (i < sl && i < dstsize - dl - 1)
	{
		dst[dl + i] = src[i];
		i++;
	}
	dst[dl + i] = '\0';
	return (dl + sl);
}
