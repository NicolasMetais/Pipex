/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:59:49 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:04:30 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || (s1[0] == '\0' && s2[0] == '\0'))
		return (0);
	if (s1[0] == '\0')
		return (-1);
	if (s2[0] == '\0')
		return (1);
	while (s1[i] == s2[i] && i < n - 1 && (s1[i] || s2[i]))
		i++;
	return ((unsigned const char)s1[i] - (unsigned const char)s2[i]);
}
/*
int main(void)
{
 	char *big = "abcdef";
 	char *little = "abcdefghijklmnop";
 	size_t size = 6;
	
 	int i1 = ((strncmp(big, little, size) > 0) ? 1 : 
	((strncmp(big, little, size) < 0) ? -1 : 0));
	
 	int i2 = ((ft_strncmp(big, little, size) > 0) ? 1 : 
	((ft_strncmp(big, little, size) < 0) ? -1 : 0));
 
 	if (i1 == i2)
 		printf("OUI");
	else
 	printf("NOPE\n");
	printf("%d\n", i1);
	printf("%d\n", i2);
}*/
