/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:10:31 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/16 21:46:49 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_boolean	args_parse(t_pipex *pipex)
{
	if (ft_strncmp(pipex->av[1], "here_doc", 8) == 0)
	{
		pipex->fork_count = pipex->ac - 4;
		pipex->limiter = pipex->av[2];
		pipex->here_doc = true;
	}
	else
	{
		pipex->fork_count = pipex->ac - 3;
		if (access(pipex->av[1], F_OK | R_OK) == -1)
			return (error_handler(2));
	}
	return (true);
}

t_boolean	env_parse(t_pipex *pipex)
{
	int		i;

	pipex->env_path = ft_split((*pipex->env), ':');
	if (!pipex->env_path)
		return (false);
	i = 0;
	if (pipex->here_doc == true)
		pipex->av = pipex->av + 3;
	else
		pipex->av = pipex->av + 2;
	pipex->cmd = malloc(sizeof(char **) * pipex->fork_count);
	if (!pipex->cmd)
		return (false);
	while (i < pipex->fork_count)
	{
		pipex->cmd[i] = ft_split(pipex->av[i], ' ');
		if (pipex->cmd[i + 1] && !pipex->cmd[i])
			return (free(pipex->cmd), 0);
		i++;
	}
	return (true);
}
