/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:19:17 by ldeville          #+#    #+#             */
/*   Updated: 2023/02/06 09:03:23 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	size_t			i;

	i = 0;
	string = (unsigned char *)s;
	while (i < n)
	{
		if (string[i] == (unsigned char)c)
			return (&string[i]);
		i++;
	}
	return (NULL);
}
