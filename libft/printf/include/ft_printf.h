/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:08:17 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:29:47 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../include/libft.h"
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
size_t	conditionner(const char *format, size_t i, va_list arg);
size_t	percentchecker(const char *format);
size_t	multiplechar(va_list arg);
size_t	singlechar(va_list arg);
size_t	hexadress(va_list arg);
size_t	inttochar(va_list arg);
size_t	unsignedinttochar(va_list arg);
char	*ft_itoa_unsigned(unsigned int n);
size_t	hexa(va_list arg, size_t bol);
size_t	percent(void);
size_t	gethexsize(unsigned long long c);
void	write_adress(size_t i, char *toprint);
size_t	converthexadress(unsigned long long c);
size_t	converthexa(unsigned long long c, size_t bol, size_t sign);

#endif