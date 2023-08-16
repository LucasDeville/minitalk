/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:55:12 by ldeville          #+#    #+#             */
/*   Updated: 2023/02/09 13:46:12 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	tmp;
	char	*m;

	i = 0;
	tmp = 0;
	while (s[tmp])
		tmp++;
	m = (char *)malloc(sizeof(*m) * (tmp + 1));
	if (!m)
		return (NULL);
	while (s[i])
	{
		m[i] = s[i];
		i++;
	}
	m[i] = 0;
	return (m);
}
