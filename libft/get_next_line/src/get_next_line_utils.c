/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:52:47 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/19 22:37:40 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

size_t	get_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*get_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = start;
	if (!s)
		return (NULL);
	if (start >= get_strlen(s))
		len = 0;
	else if (len > get_strlen(s) - start)
		len = get_strlen(s) - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (j < len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*get_strchr(const char *s, int c)
{
	int				i;
	unsigned char	d;

	if (!s || !c)
		return (NULL);
	i = 0;
	d = (unsigned char) c;
	if (d == '\0')
		return ((char *)s + get_strlen(s));
	while (s[i])
	{
		if (s[i] == d)
			return ((char *) s + i);
		i++;
	}
	return (NULL);
}

char	*get_strjoin( char *s1, char*s2)
{
	int		i;
	size_t	j;
	char	*str;
	int		size1;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	size1 = get_strlen(s1);
	str = malloc(sizeof(char) * ((int)size1 + (int)get_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (i++, i < size1)
		str[i] = s1[i];
	j = 0;
	while (i < size1 + (int)get_strlen(s2))
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
