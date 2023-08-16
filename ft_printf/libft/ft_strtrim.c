/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:34:43 by ldeville          #+#    #+#             */
/*   Updated: 2023/02/09 13:47:49 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_check(char const s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	y;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	y = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_check(s1[i], set))
		i++;
	if (s1[i] == 0)
		return (ft_strdup(""));
	while (s1[j] && ft_check(s1[j], set))
		j--;
	str = malloc(sizeof(*str) * ((j + 1) - i + 1));
	if (!str)
		return (NULL);
	while (s1[i] && i <= j)
		str[y++] = s1[i++];
	str[y] = 0;
	return (str);
}
