/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:05:04 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:04:38 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	countleft(const char *set, const char *s1)
{
	size_t	j;
	size_t	i;
	size_t	check;

	j = 0;
	check = 0;
	i = 0;
	while (s1[i])
	{
		j = 0;
		check = 0;
		while (set[j])
		{
			if (s1[i] != set[j])
				check++;
			j++;
		}
		if (check == ft_strlen(set))
			return (i);
		i++;
	}
	return (0);
}

static size_t	countright(const char *set, const char *s1)
{
	size_t	j;
	size_t	check;
	size_t	i;
	size_t	count;

	count = 0;
	j = 0;
	check = 0;
		i = ft_strlen(s1) - 1;
	while (s1[i] || ft_strlen(set) != 0)
	{
		check = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] != set[j])
				check++;
			j++;
		}
		if (check == ft_strlen(set))
			return (count);
		i--;
		count++;
	}
	return (0);
}

static char	*trim(const char *s1, char *str, const char *set)
{
	size_t	i;
	size_t	k;
	size_t	left;
	size_t	right;

	k = 0;
	i = 0;
	left = countleft(set, s1);
	right = countright(set, s1);
	while (s1[i])
	{
		if (i >= left && i < ft_strlen(s1) - right)
		{
			str[k] = s1[i];
			k++;
		}
		i++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	left;
	size_t	right;
	size_t	count;

	count = 0;
	left = countleft(set, s1);
	right = countright(set, s1);
	str = ft_calloc(sizeof(char), (ft_strlen(s1) + 1) - (right + left));
	if (!str)
		return (NULL);
	if (ft_strlen(s1) - (right + left) == 0)
		return (str);
	trim(s1, str, set);
	return (str);
}
/*
int main(void)
{

 	char *ret = ft_strtrim("   Hello \t  Please\n Trim me !\t\t ", " \n\t");
	printf("%s",ret);
	free(ret);
}*/