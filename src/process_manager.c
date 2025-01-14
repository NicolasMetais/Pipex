/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:27:58 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/14 05:41:38 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fd_setup(t_pipex *pipex, int *pipe_fd, int i)
{
	if (i == 0)
	{
		dup2(pipex->input_fd, STDIN_FILENO);
		close(pipex->input_fd);
	}
	else
		dup2(pipe_fd[0], STDIN_FILENO);
	if (i < pipex->fork_count - 1)
		dup2(pipe_fd[1], STDOUT_FILENO);
	else
	{
		dup2(pipex->outfile_fd, STDOUT_FILENO);
		close(pipex->outfile_fd);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	env_exec(pipex, i);
	perror("exec");
	exit(EXIT_FAILURE);
}

void	fork_process(t_pipex *pipex, pid_t pid, int *pipe_fd, int i)
{
	if (pid == 0)
	{
		close(pipe_fd[0]);
		fd_setup(pipex, pipe_fd, i);
	}
	else
	{
		close(pipe_fd[1]);
		if (i > 0)
			close(pipe_fd[0]); 
		pipex->input_fd = pipe_fd[0];
	}
}
