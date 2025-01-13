/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:11:45 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:42:36 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Recherche la dernière occurrence du caractère */
#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	size_t			len;
	unsigned char	d;

	d = (unsigned char ) c;
	len = ft_strlen(s) + 1;
	i = 0;
	while (len)
	{		
		len--;
		if (s[len] == d)
			return ((char *) s + len);
	}
	return (NULL);
}
/*
int main(void)
{
	char test[] = "jtirgigigjniuijifejin";
	char *res;
	res = ft_strrchr(test, 'n');
	//res = strrchr(test, 'n');
	printf("%s", res);
}*/