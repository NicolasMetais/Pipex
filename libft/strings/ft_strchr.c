/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:21:41 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:43:12 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Rechercher un caractère dans une chaîne  */
#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	d;

	if (!s || !c)
		return (NULL);
	i = 0;
	d = (unsigned char) c;
	if (d == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == d)
			return ((char *) s + i);
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
 	char *src = "the cake is a lie !\0I'm hidden lol\r\n";
 	char *d1 = strchr(src, 't' + 256);
 	char *d2 = ft_strchr(src, 't' + 256);
	char *d3 = strchr("teste",'\0');
	char *d4 = ft_strchr("teste", '\0');
 	if (d1 == d2)
 		printf("Y E S");
	else
	{
 		printf("N O P E\n");
		printf("strchr :%s\n", d1);
		printf("ft_strchr :%s\n", d2);
	}
	if (d3 == d4)
 		printf("Y E S");
		else
	{
 		printf("N O P E\n");
		printf("%s\n", d3);
		printf("%s\n", d4);
	}
}*/
