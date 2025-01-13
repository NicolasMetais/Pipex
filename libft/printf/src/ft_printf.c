/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 00:18:04 by nmetais           #+#    #+#             */
/*   Updated: 2024/11/25 14:02:11 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/ft_printf.h"

int	countformatspecifiers(const char *format)
{
	size_t	i;
	size_t	percent;
	size_t	argcount;

	i = 0;
	percent = 0;
	argcount = 0;
	while (format[i])
	{
		if (format[i] == '%' && percentchecker(format + i) == 1)
			percent += 1;
		i++;
	}
	if (percent == 0)
		return (1);
	return (0);
}

size_t	printer(const char *format, va_list arg)
{
	size_t	i;
	size_t	size;
	size_t	count;

	i = 0;
	size = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			size += conditionner(format, i, arg);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	i++;
	}
	return (count + size);
}

int	ft_printf(const char *format, ...)
{
	size_t	size;
	va_list	arg;

	size = 0;
	if (countformatspecifiers(format) == 1)
		return (write(1, "NULL", 1));
	va_start(arg, format);
	size = printer(format, arg);
	va_end(arg);
	return (size);
}
/*
#include <stdio.h>
int main(void)
{ 
	//char u[] = "test";
	int test;
	int test1;

	test = ft_printf(" %x ", -100);
	test1 = printf(" %x ", -100);
	printf("\nft_printf:%d\n printf: %d", test, test1);
}*/