/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 00:16:48 by nmetais           #+#    #+#             */
/*   Updated: 2024/11/25 13:56:59 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/ft_printf.h"

size_t	conditionner(const char *format, size_t i, va_list arg)
{
	size_t	writtedsize;

	writtedsize = 0;
	if (format[i] == '%' && format[i + 1] == 'c')
		writtedsize = singlechar(arg);
	if (format[i] == '%' && format[i + 1] == 's')
		writtedsize = multiplechar(arg);
	if (format[i] == '%' && format[i + 1] == 'p')
		writtedsize = hexadress(arg);
	if (format[i] == '%' && format[i + 1] == 'd')
		writtedsize = inttochar(arg);
	if (format[i] == '%' && format[i + 1] == 'i')
		writtedsize = inttochar(arg);
	if (format[i] == '%' && format[i + 1] == 'u')
		writtedsize = unsignedinttochar(arg);
	if (format[i] == '%' && format[i + 1] == 'x')
		writtedsize = hexa(arg, 0);
	if (format[i] == '%' && format[i + 1] == 'X')
		writtedsize = hexa(arg, 1);
	if (format[i] == '%' && format[i + 1] == '%')
		writtedsize = percent();
	return (writtedsize);
}

size_t	percentchecker(const char *format)
{
	char	*check1;
	char	concat[3];
	size_t	i;

	check1 = "cspdiuxX%";
	i = 0;
	while (check1[i])
	{
		concat[0] = '%';
		concat[1] = check1[i];
		concat[2] = '\0';
		if (ft_strnstr(format, concat, 2) != NULL )
			return (1);
		i++;
	}
	return (0);
}
