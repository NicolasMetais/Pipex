/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 01:44:24 by nmetais           #+#    #+#             */
/*   Updated: 2024/11/24 23:00:59 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/ft_printf.h"

size_t	multiplechar(va_list arg)
{
	char	*s;

	s = va_arg(arg, char *);
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

size_t	singlechar(va_list arg)
{
	char	c;

	c = va_arg(arg, int);
	return (write(1, &c, 1));
}

size_t	percent(void)
{
	return (write(1, "%", 1));
}
