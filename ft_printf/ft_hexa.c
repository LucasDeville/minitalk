/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:27:46 by ldeville          #+#    #+#             */
/*   Updated: 2023/02/17 10:52:59 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_dohexa(unsigned int nb, int maj)
{
	if (nb >= 16)
	{
		ft_dohexa(nb / 16, maj);
		ft_dohexa(nb % 16, maj);
	}
	else
	{
		if (nb < 10)
			ft_putchar_pf((nb + '0'));
		else
		{
			if (maj)
				ft_putchar_pf((nb - 10 + 'A'));
			else
				ft_putchar_pf((nb - 10 + 'a'));
		}
	}
}

int	ft_puthexa(unsigned int nb, int maj)
{
	int				i;
	unsigned int	tmp;

	i = 0;
	tmp = nb;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		i++;
	}
	if (nb == 0)
		return (ft_putchar_pf('0'));
	ft_dohexa(nb, maj);
	return (i);
}

void	ft_puthexadress(unsigned long long nb)
{
	if (nb >= 16)
	{
		ft_puthexadress(nb / 16);
		ft_puthexadress(nb % 16);
	}
	else
	{
		if (nb < 10)
			ft_putchar_pf((nb + '0'));
		else
			ft_putchar_pf((nb - 10 + 'a'));
	}
}

int	ft_hexadresslen(unsigned long long str)
{
	int	i;

	i = 0;
	while (str != 0)
	{
		str = str / 16;
		i++;
	}
	return (i);
}

int	ft_hexadress_pf(unsigned long long str)
{
	if (str == 0)
		return (ft_putstr_pf("(nil)"));
	ft_putstr_pf("0x");
	ft_puthexadress(str);
	return (2 + (ft_hexadresslen(str)));
}
