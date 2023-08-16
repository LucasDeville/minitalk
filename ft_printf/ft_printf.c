/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:13:37 by ldeville          #+#    #+#             */
/*   Updated: 2023/02/17 10:53:10 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printarg(const char str, va_list arg)
{
	if (str == 'c')
		return (ft_putchar_pf(va_arg(arg, int)));
	else if (str == 's')
		return (ft_putstr_pf(va_arg(arg, char *)));
	else if (str == 'p')
		return (ft_hexadress_pf(va_arg(arg, unsigned long long)));
	else if (str == 'd')
		return (ft_itoa_pf(va_arg(arg, int)));
	else if (str == 'i')
		return (ft_itoa_pf(va_arg(arg, int)));
	else if (str == 'u')
		return (ft_uitoa_pf(va_arg(arg, unsigned int)));
	else if (str == 'x')
		return (ft_puthexa(va_arg(arg, unsigned int), 0));
	else if (str == 'X')
		return (ft_puthexa(va_arg(arg, unsigned int), 1));
	else
		return (ft_putchar_pf('%'));
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		count;
	va_list	arg;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			count += ft_printarg(str[++i], arg);
		else
		{
			ft_putchar_pf(str[i]);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
