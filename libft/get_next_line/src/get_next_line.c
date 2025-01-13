/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:52:45 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/08 17:42:59 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*read_a_line(int fd, char *buffer)
{
	int		pos;
	char	*toread;

	pos = 40;
	toread = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!toread)
		return (NULL);
	while (!get_strchr(buffer, '\n') && pos != 0)
	{
		pos = read(fd, toread, BUFFER_SIZE);
		if (pos < 0)
			return (free(toread), NULL);
		toread[pos] = '\0';
		buffer = get_strjoin(buffer, toread);
	}
	free(toread);
	return (buffer);
}

char	*cutline(char *buffer)
{
	size_t	i;
	char	*toprint;
	size_t	size;

	i = 0;
	size = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		size = 1;
	toprint = get_substr(buffer, 0, i + size);
	if (!toprint)
		return (NULL);
	return (toprint);
}

char	*setupbuffer(char *buffer)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*newbuff;

	j = 0;
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i] || !buffer[i + 1])
	{
		free(buffer);
		return (NULL);
	}
	size = get_strlen(buffer) - i + 1;
	newbuff = malloc (size * sizeof(char));
	if (!newbuff)
		return (NULL);
	i++;
	while (buffer[i])
		newbuff[j++] = buffer[i++];
	newbuff[j] = '\0';
	free(buffer);
	return (newbuff);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*toprint;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buffer = read_a_line(fd, buffer);
	if (!buffer)
		return (NULL);
	toprint = cutline(buffer);
	buffer = setupbuffer(buffer);
	return (toprint);
}

int	main(int arc, char **arv)
{
	int		fd;
	char	*ret;

	if (arc == 2)
	{
		fd = open(arv[1], O_RDONLY);
		ret = get_next_line(fd);
		while (ret)
		{
			printf("%s", ret);
			free(ret);
			ret = get_next_line(fd);
		}
	}
}