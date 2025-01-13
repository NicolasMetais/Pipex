/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:24:41 by nmetais           #+#    #+#             */
/*   Updated: 2024/11/25 13:56:43 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/ft_printf.h"

size_t	inttochar(va_list arg)
{
	int		c;
	char	*res;
	int		len;

	c = va_arg(arg, int);
	res = ft_itoa(c);
	len = write(1, res, ft_strlen((char *)res));
	free(res);
	return (len);
}

size_t	unsignedinttochar(va_list arg)
{
	int		c;
	char	*res;
	int		len;

	c = va_arg(arg, int);
	res = ft_itoa_unsigned(c);
	len = write(1, res, ft_strlen((char *)res));
	free(res);
	return (len);
}
