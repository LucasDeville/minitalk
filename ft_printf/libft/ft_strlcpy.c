/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:24:10 by ldeville          #+#    #+#             */
/*   Updated: 2023/02/07 11:26:19 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		len ++;
	if (size != 0)
	{
		size--;
		while (i < len && i < size)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (len);
}
