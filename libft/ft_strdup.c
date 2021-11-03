/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:39:37 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/03 14:44:37 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char *ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ret;

	if (s1 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	ret = malloc((i + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_strcpy(ret, s1);
	return (ret);
}