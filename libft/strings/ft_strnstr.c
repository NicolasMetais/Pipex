/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:03:40 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:04:32 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* locate a substring in a string */
#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(little) == 0 || little == NULL)
		return ((char *)big);
	if (ft_strlen(big) == 0 || ft_strlen(little) > len)
		return (NULL);
	while (len > i)
	{
		if (ft_strncmp((char *) &big[i], little, ft_strlen(little)) == 0)
		{
			if (i + ft_strlen(little) > len)
				return (NULL);
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
