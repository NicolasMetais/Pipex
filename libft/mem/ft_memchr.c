/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:05:49 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:03:28 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Rechercher un caractère dans une zone mémoire */
#include "../include/libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	char	*cs;
	size_t	i;

	cs = s;
	i = 0;
	while (i < n)
	{
		if (cs[i] == (char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	int s[] = {1,2,3,4,5};
	char *r1 = ft_memchr(s, 2 + 256, 3);
	char *r2 = memchr(s, 2 + 256, 3);
	printf("%s\n", r1);
	printf("%s", r2);
}*/
