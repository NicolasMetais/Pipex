/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:17:41 by nmetais           #+#    #+#             */
/*   Updated: 2024/11/25 13:58:29 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/ft_printf.h"

size_t	hexadress(va_list arg)
{
	unsigned long long		c;
	int						len;

	c = va_arg(arg, unsigned long long);
	if (c == 0)
		return (write (1, "(nil)", 5));
	write (1, "0x", 2);
	len = converthexadress(c) + 2;
	return (len);
}

size_t	hexa(va_list arg, size_t bol)
{
	int		c;
	size_t	sign;

	sign = 0;
	c = va_arg(arg, int);
	if (c < 0)
		sign++;
	return (converthexa((int)c, bol, sign));
}
