/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:26:32 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/19 22:40:47 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "unistd.h"

void	pipex_init(t_pipex *pipex, int ac, char **av, char **env)
{
	while ((ft_strncmp(*env, "PATH=", 5)))
		env++;
	pipex->env = env;
	pipex->cmd = NULL;
	pipex->av = av;
	pipex->ac = ac;
	pipex->here_doc = false;
}

t_boolean	here_doc_or_not(t_pipex *pipex)
{
	if (pipex->here_doc == true)
		here_doc(pipex);
	else
	{
		if (dup2(pipex->input_fd, STDIN_FILENO) == -1)
			return (free_all(pipex), false);
		close(pipex->input_fd);
	}
	return (true);
}

t_boolean	core(t_pipex *pipex)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (!here_doc_or_not(pipex))
		return (false);
	while (i < pipex->fork_count)
	{
		if (pipe(pipex->pipe_fd) == -1)
			return (free_all(pipex), false);
		pid = fork();
		if (pid == -1)
			return (free_all(pipex), false);
		if (!fork_process(pipex, pid, i))
			return (free_all(pipex), false);
		i++;
	}
	while (wait(NULL) != -1)
		;
	free_all(pipex);
	return (true);
}

t_boolean	open_files(t_pipex *pipex)
{
	if (pipex->here_doc == true)
	{
		pipex->outfile_fd = open(pipex->av[pipex->ac -1],
				O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (pipex->outfile_fd == -1)
			return (false);
	}
	else
	{
		pipex->input_fd = open(pipex->av[1], O_RDONLY);
		if (pipex->outfile_fd == -1)
			return (false);
		pipex->outfile_fd = open(pipex->av[pipex->ac -1],
				O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (pipex->outfile_fd == -1)
			return (close(pipex->input_fd), false);
	}
	return (true);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	int		input_fd;

	if (!env[0])
	{
		return (0);
	}
	input_fd = 0;
	pipex.input_fd = input_fd;
	if (ac > 4)
	{
		pipex_init(&pipex, ac, av, env);
		if (!args_parse(&pipex))
			return (0);
		if (!open_files(&pipex))
			return (0);
		if (!env_parse(&pipex))
			return (0);
		if (!core(&pipex))
			return (0);
		close(pipex.outfile_fd);
	}
}
