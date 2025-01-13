/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:37:54 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:03:31 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Comparaison de zones mémoire */
#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*cs1;
	unsigned const char	*cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	i = 0;
	while ((cs1 || cs2) && i < n)
	{
		if (cs1[i] == cs2[i])
			i++;
		else
		{
			return (cs1[i] - cs2[i]);
		}
	}
	return (0);
}
/*
int main(void)
{
	char s1[] = "test";
	char s2[] = "tesp";
	int s3[] = {2, 10 , 20 , 30 , 40};
	int s4[] = {1, 10 , 30 , 30 , 5};
	int res;
	res = ft_memcmp(s1, s2,0);
	printf("%d\n", res);
	res = memcmp(s1, s2 , 0);
	printf("%d\n", res);
	res = ft_memcmp(s3, s4 , 0);
	printf("%d\n", res);
	res = memcmp(s3, s4 , 0);
	printf("%d\n", res);
	res = memcmp(s1, s3 , 5);
	printf("%d\n", res);
	res = memcmp(s1, s3 , 5);
	printf("%d\n", res);
}*/