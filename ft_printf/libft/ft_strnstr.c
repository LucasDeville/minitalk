/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:33:30 by ldeville          #+#    #+#             */
/*   Updated: 2023/02/09 13:43:12 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	if ((!big || !little) && !len)
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		l = 0;
		if (big[i] == little[l])
		{
			while (little[l] && big[i + l] && big[i + l] == little[l]
				&& (i + l) < len)
				l++;
			if (little[l] == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
