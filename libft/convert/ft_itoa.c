/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:32:51 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:02:39 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	int	getintsize(long cn)
{
	size_t	i;

	i = 0;
	if (cn == 0)
		return (1);
	while (cn != 0)
	{
		cn = cn / 10;
		i++;
	}
	return (i);
}

static	char	*reverse(char *str, size_t nega, size_t count)
{
	size_t	i;
	size_t	j;
	char	temp;

	i = 0;
	j = count;
	if (nega == 1)
		i++;
	while (i < count)
	{
		temp = str[count - 1];
		str[count - 1] = str[i];
		str[i] = temp;
		count--;
		i++;
	}
	return (str);
}

static	char	*convert(int long cn, char *str, size_t nega, size_t count)
{
	size_t	i;

	i = 0;
	if (nega == 1)
	{
		str[0] = '-';
		i++;
	}
	while (i < count)
	{
		str[i] = (cn % 10) + '0';
		cn = cn / 10;
		i++;
	}
	str[i] = '\0';
	reverse(str, nega, count);
	return (str);
}

char	*ft_itoa(int n)
{
	size_t		count;
	size_t		nega;
	char		*str;
	long		cn;

	cn = n;
	nega = 0;
	if (cn < 0)
	{
		nega = 1;
		cn = cn * -1;
	}
	count = getintsize(n);
	if (nega == 1)
		count++;
	str = ft_calloc(sizeof(char), count + 1);
	if (!str)
		return (NULL);
	str = convert(cn, str, nega, count);
	return (str);
}
/*
int	main(void)
{
	char	*str;

	str = ft_itoa(0);
	printf("%s", str);
	free(str);
}*/