/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:46:50 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/19 22:17:45 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc_process(t_pipex *pipex)
{
	int		cmp;
	char	*line;
	size_t	size;

	cmp = 40;
	size = ft_strlen(pipex->limiter);
	close(pipex->pipe_fd[0]);
	while (1)
	{
		ft_putstr_fd("heredoc> ", 2);
		line = get_next_line(0);
		if (!line)
			break ;
		cmp = ft_strncmp(line, pipex->limiter, size);
		if (cmp == 0 && (ft_strlen(line) - 1) == size)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, pipex->pipe_fd[1]);
		free(line);
	}
	close(pipex->pipe_fd[1]);
}

void	here_doc(t_pipex *pipex)
{
	pid_t	pid;

	pipe(pipex->pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		close(pipex->pipe_fd[0]);
		here_doc_process(pipex);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipex->pipe_fd[1]);
		dup2(pipex->pipe_fd[0], STDIN_FILENO);
		close(pipex->pipe_fd[0]);
		wait(NULL);
	}
}
