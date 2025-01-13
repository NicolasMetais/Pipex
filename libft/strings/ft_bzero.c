/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:28:59 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:03:48 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* bzero - Écrire des octets de valeur zéro dans un bloc d'octets */
#include "../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*t;

	t = s;
	i = 0;
	while (i < n)
	{
		t[i] = 0;
		i++;
	}
}
/*
#include <string.h>
int main(void)
{
	char test[] = "AAAAAAAAAAAAAA";
	char test1[] = "AAAAAAAAAAAAAA";

	ft_bzero(test,ft_strlen(test));
	bzero(test1, ft_strlen(test));
	printf("%s\n", test);
	printf("%s", test1);
}*/
