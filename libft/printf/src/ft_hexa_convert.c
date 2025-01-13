/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:58:15 by nmetais           #+#    #+#             */
/*   Updated: 2024/11/25 14:00:17 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/ft_printf.h"

size_t	gethexsize(unsigned long long c)
{
	size_t	i;

	i = 0;
	while ((c / 16) > 0)
	{
		c /= 16;
		i++;
	}
	return (i);
}

void	write_adress(size_t i, char *toprint)
{
	while (i > 0)
	{
		write(1, &toprint[i], 1);
		i--;
	}
	write(1, &toprint[i], 1);
	free(toprint);
}

size_t	converthexadress(unsigned long long c)
{
	char	*base;
	char	*toprint;
	size_t	i;
	size_t	size;

	i = 0;
	base = "0123456789abcdef";
	size = gethexsize(c);
	toprint = ft_calloc(sizeof(char), size + 2);
	if (!toprint)
		return (0);
	while ((c / 16) > 0)
	{
		toprint[i] = base[(c % 16)];
		c /= 16;
		i++;
	}
	toprint[i] = base[(c % 16)];
	toprint[i + 1] = '\0';
	write_adress(i, toprint);
	return (size + 1);
}

size_t	converthexa(unsigned long long c, size_t bol, size_t sign)
{
	char	*base;
	char	*toprint;
	size_t	i;
	size_t	size;

	i = 0;
	base = "0123456789abcdef";
	if (bol == 1)
		base = "0123456789ABCDEF";
	size = gethexsize(c);
	if (sign == 1)
		size = 7;
	toprint = ft_calloc(sizeof(char), size + 2);
	if (!toprint)
		return (0);
	while ((c / 16) > 0 && i < 7)
	{
		toprint[i] = base[(c % 16)];
		c /= 16;
		i++;
	}
	toprint[i] = base[(c % 16)];
	toprint[i + 1] = '\0';
	write_adress(i, toprint);
	return (size + 1);
}
