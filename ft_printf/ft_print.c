/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:22:12 by ldeville          #+#    #+#             */
/*   Updated: 2023/04/03 13:43:39 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar_pf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_pf(char *str)
{
	if (!str)
		return (ft_putstr_pf("(null)"));
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_itoa_pf(int nb)
{
	char	*nbr;
	int		size;

	size = 0;
	nbr = ft_itoa(nb);
	size = ft_putstr_pf(nbr);
	free(nbr);
	return (size);
}

char	*ft_uitoa(unsigned int nb, int size)
{
	char	*str;

	str = malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = 0;
	while (nb != 0)
	{
		str[--size] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (str);
}

int	ft_uitoa_pf(unsigned int nb)
{
	char			*nbr;
	int				size;
	unsigned int	tmp;

	size = 0;
	tmp = nb;
	if (nb == 0)
		return (ft_putchar_pf('0'));
	while (tmp != 0)
	{
		tmp = tmp / 10;
		size++;
	}
	nbr = ft_uitoa(nb, size);
	size = ft_putstr_pf(nbr);
	free(nbr);
	return (size);
}
