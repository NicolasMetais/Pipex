/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:22:25 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:04:18 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = ft_strlen(src);
	j = ft_strlen(dst);
	if (j >= siz || siz == 0)
		return (siz + k);
	while (i < (siz - j - 1) && src[i] != '\0')
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (k + j);
}
/*
int main(void)
{
	//r2 = ft_strlcat("pqrstuvwxyz", "abcd", 20);
 	printf("%zu",ft_strlcat("pqrstuvwxyz", "abcd", 20));
}*/
