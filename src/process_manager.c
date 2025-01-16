/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:27:58 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/16 05:43:57 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_process(t_pipex *pipex, pid_t pid, int i)
{
	if (pid == 0)
	{
		if (i == pipex->fork_count - 1)
		{
			close(pipex->pipe_fd[0]);
			dup2(pipex->outfile_fd, STDOUT_FILENO);
			close(pipex->outfile_fd);
		}
		else
		{
			close(pipex->pipe_fd[0]);
			dup2(pipex->pipe_fd[1], STDOUT_FILENO);
			close(pipex->pipe_fd[1]);
		}
		env_exec(pipex, i);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipex->pipe_fd[1]);
		if(i > 0)
			close(pipex->pipe_fd[0]);
		dup2(pipex->pipe_fd[0], STDIN_FILENO);
	}
}
