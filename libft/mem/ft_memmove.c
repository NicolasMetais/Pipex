/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:49:57 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:03:37 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Copier une zone mémoire */
#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*csrc;
	char		*cdest;

	csrc = src;
	cdest = dest;
	if (cdest <= csrc)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			cdest[n - 1] = csrc[n - 1];
			n--;
		}
	}
	return (dest);
}
/*
int main(void)
{
	char cpy[] = "consectetur";
	char dest[];
	ft_memmove(dest, cpy, 5);
	
}*/
