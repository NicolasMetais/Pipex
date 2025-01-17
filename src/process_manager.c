/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:27:58 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/17 01:20:49 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_boolean	child_dup(t_pipex *pipex, int i)
{
	if (i == pipex->fork_count - 1)
	{
		close(pipex->pipe_fd[0]);
		if (dup2(pipex->outfile_fd, STDOUT_FILENO) < 0)
			return (false);
		close(pipex->outfile_fd);
	}
	else
	{
		close(pipex->pipe_fd[0]);
		if (dup2(pipex->pipe_fd[1], STDOUT_FILENO) < 0)
			return (false);
		close(pipex->pipe_fd[1]);
	}
}

t_boolean	fork_process(t_pipex *pipex, pid_t pid, int i)
{
	if (pid == 0)
	{
		if (child_dup(pipex, i))
			return (false);
		if (env_exec(pipex, i))
			return (false);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipex->pipe_fd[1]);
		if (dup2(pipex->pipe_fd[0], STDIN_FILENO) < 0)
			return (false);
		close(pipex->pipe_fd[0]);
	}
	return (true);
}
