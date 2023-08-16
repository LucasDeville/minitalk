/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:17:47 by ldeville          #+#    #+#             */
/*   Updated: 2023/02/09 13:48:12 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_actualword(char const *s, char c, int a)
{
	size_t	i;

	i = a;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static	int	ft_nextword(char const *s, char c, int a)
{
	size_t	i;

	i = a;
	while (s[i] && s[i] != c)
		i++;
	return (++i);
}

static	int	ft_countword(char const *s, char c)
{
	size_t	i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	countw;
	size_t	actualw;
	size_t	nextw;
	char	**str;

	if (!s)
		return (NULL);
	i = 0;
	countw = ft_countword(s, c);
	actualw = 0;
	nextw = 0;
	str = malloc(sizeof(char *) * (countw + 1));
	if (!str)
		return (NULL);
	while (i < countw)
	{
		actualw = ft_actualword(s, c, nextw);
		nextw = ft_nextword(s, c, actualw);
		str[i] = malloc(sizeof(char) * (nextw - actualw));
		ft_strlcpy(str[i], s + actualw, (nextw - actualw));
		i++;
	}
	str[i] = 0;
	return (str);
}
