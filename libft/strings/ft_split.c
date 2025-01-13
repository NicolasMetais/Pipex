/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:31:48 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/11 16:15:31 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	size_t	wordcount(char const *s, char c)
{
	size_t	i;
	size_t	word;
	size_t	bol;

	i = 0;
	word = 0;
	bol = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
		i++;
		bol = 1;
	}
	return (word);
}

static char	**freeme(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static	void	findtheword(char **findword, size_t *wordsize, char c)
{
	size_t	i;

	*findword = *findword + *wordsize;
	*wordsize = 0;
	while (**findword && **findword == c)
		(*findword)++;
	i = 0;
	while ((*findword)[i])
	{
		if ((*findword)[i] == c)
			return ;
		(*wordsize)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**str;
	size_t	wordsize;
	char	*findword;

	i = 0;
	wordsize = 0;
	str = ft_calloc(sizeof(char *), wordcount(s, c) + 1);
	if (!str)
		return (NULL);
	findword = (char *)s;
	while (i < wordcount(s, c))
	{
		findtheword(&findword, &wordsize, c);
		str[i] = ft_calloc(sizeof(char), wordsize + 1);
		if (!str[i])
			return (freeme(str));
		ft_strlcpy(str[i], findword, wordsize + 1);
		i++;
	}
	str[i] = 0;
	return (str);
}
/* 
int main(void)
{
 	char **result = ft_split("1", ' ');
	int i = 0;

 
 	while (result[i])
 	{
		printf("%s", result[i]);
 		free(result[i]);
 		i++;
 	}
 	free(result);

} */
