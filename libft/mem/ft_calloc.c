/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:45:42 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:03:25 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*al;

	i = 0;
	if (nmemb * size > 2147483647)
		return (NULL);
	al = malloc(nmemb * size);
	if (al == NULL)
		return (NULL);
	while (i < (nmemb * size))
	{
		al[i] = 0;
		i++;
	}
	return ((void *)al);
}
/*
int main(void)
{
	char *res;
	res = ft_calloc(10, 8);
	if (res[0] == '\0')
	printf("Yes");
	else
	printf("No");
}*/