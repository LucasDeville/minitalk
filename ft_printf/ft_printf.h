/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:34:07 by ldeville          #+#    #+#             */
/*   Updated: 2023/02/18 08:13:44 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <assert.h>
# include <stdarg.h>

int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *str);
int	ft_itoa_pf(int nb);
int	ft_puthexa(unsigned int nb, int maj);
int	ft_hexadress_pf(unsigned long long str);
int	ft_printf(const char *str, ...);
int	ft_uitoa_pf(unsigned int nb);

#endif
