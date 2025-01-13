/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:03:48 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:04:10 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Dupliquer une chaîne */
#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*cpy;

	i = 0;
	len = ft_strlen(s);
	cpy = malloc(len * sizeof(char) + 1);
	if (cpy == NULL)
		return (NULL);
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return ((void *)cpy);
}
/*
int main(void)
{
	char test[] = "ceci est test";
	printf("ft_strdup :%s/n", ft_strdup(test));
	printf("strdup :%s", strdup(test));
}*/