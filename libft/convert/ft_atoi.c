/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:33:29 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:02:29 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		res;
	int		bol;

	res = 0;
	i = 0;
	bol = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
	i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		bol = 1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10;
		res = res + (nptr[i] - '0');
		i++;
	}
	if (bol == 1)
		res = res * (-1);
	return (res);
}
/*
int main(void)
{
 	char *n = "2147483655";
 	int i1 = atoi(n);
 	int i2 = ft_atoi(n);
 
 	if (i1 == i2)
 		printf("YEP\n");
	else
 	printf("NO\n");
	printf("atoi %d\n", i1);
	printf("ft atoi%d\n", i2);

}*/