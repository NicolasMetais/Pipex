/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:00:50 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:04:21 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	res;

	res = ft_strlen(src);
	i = 0;
	if (siz != 0)
	{
		while (i < siz - 1 && i < res)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (res);
}
/*
int	main(void)
{
	char *str = "XXXX";
	char buff1[3000];
	char buff2[3000];
	size_t res1;
	size_t res2;
	int		res3;
	memset(buff1, 'A', 20);
	memset(buff2, 'A', 20);
	res1 = ft_strlcpy(buff1, str, sizeof(buff1));
	res2 = strlcpy(buff2, str, sizeof(buff2));
	if (!ft_memcmp(buff1, buff2, 20))
		printf("YES");
	else
	{
		res3 = ft_memcmp(buff1, buff2, 20);
		printf("\n%d",res3);
	}
}*/