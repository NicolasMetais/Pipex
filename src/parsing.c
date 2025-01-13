/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:10:31 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/13 01:58:45 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	args_parse(t_pipex *pipex)
{
	int		error;
	int		i;
	int		j;

	i = 2;
	error = access(pipex->av[1], F_OK | R_OK);
	if (error == -1)
		return (error_handler(2));
	while (i < pipex->fork_count)
	{
		j = 0;
		while (pipex->av[i][j])
		{
			if (pipex->av[i][0] == '/')
				pipex->absolute_path = true;
			j++;
		}
		i++;
	}
	pipex->infile_fd = open(pipex->av[1], O_RDONLY);
	pipex->outfile_fd = open(pipex->av[pipex->fork_count + 1], O_CREAT, O_RDWR);
	return (true);
}

int	env_parse(t_pipex *pipex)
{
	int		i;

	pipex->env_path = ft_split((*pipex->env), ':');
	i = 0;
	pipex->av = pipex->av + 2;
	pipex->cmd = malloc(sizeof(char **) * pipex->fork_count);
	if (!pipex->cmd)
		return (error_handler(false));
	while (i < pipex->fork_count - 1)
	{
		pipex->cmd[i] = ft_split(pipex->av[i], ' ');
		i++;
	}
	return (true);
}
