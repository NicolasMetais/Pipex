/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:46:50 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/17 04:40:28 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc_process(t_pipex *pipex)
{
	int		cmp;
	char	*line;
	size_t	size;

	cmp = 40;
	size = ft_strlen(pipex->limiter); //A CHANGER
	close(pipex->pipe_fd[0]);
	while (1)
	{
		ft_putstr_fd("heredoc> ", 2);
		line = get_next_line(0);
		cmp = ft_strncmp(line, pipex->limiter, size);
		if (cmp == 0)
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
		wait(NULL);
	}
//valgrind --track-fds=yes --trace-children=yes  ./pipex here_doc EOF "grep test" "wc -l" file7
}
