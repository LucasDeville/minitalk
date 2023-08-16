/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:20:09 by ldeville          #+#    #+#             */
/*   Updated: 2023/02/09 13:40:17 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	index;
	size_t	total;

	i = 0;
	if (!size && (!src || !dest))
		return (0);
	index = ft_strlen(src);
	total = ft_strlen(dest);
	if (size <= total)
		return (index + size);
	while (dest[i] && i < size)
		i++;
	if ((size - i) == 0)
		return (i + index);
	total += index;
	index = 0;
	while (i < (size - 1) && src[index])
	{
		dest[i] = src[index];
		i++;
		index++;
	}
	dest[i] = 0;
	return (total);
}
