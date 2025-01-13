/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:49:54 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:03:34 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copier une zone mémoire */
#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*cdest;
	const char	*csrc;
	size_t		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	csrc = src;
	cdest = dest;
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
/*
int main(void)
{
	//memcpy(((void*)0), ((void*)0), 3);


	ft_memcpy(((void*)0), ((void*)0), 3);


}*/
