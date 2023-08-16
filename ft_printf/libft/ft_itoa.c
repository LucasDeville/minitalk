/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:53:45 by ldeville          #+#    #+#             */
/*   Updated: 2023/02/07 13:37:35 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_recur(int n, char *str)
{
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n > 9)
	{
		ft_recur(n / 10, str);
		ft_recur(n % 10, str);
	}
	else
	{
		str[ft_strlen(str)] = n + 48;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nbr;
	size_t	i;

	nbr = n;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0 || n < 0)
		i++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	str = malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	ft_bzero(str, i + 1);
	ft_recur(n, str);
	str[ft_strlen(str)] = 0;
	return (str);
}
