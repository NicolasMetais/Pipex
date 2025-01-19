/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:26:32 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/19 20:57:32 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "unistd.h"

void	free_all(t_pipex *pipex)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (pipex->env_path[i])
	{
		free(pipex->env_path[i]);
		i++;
	}
	free (pipex->env_path);
	i = 0;
	while (pipex->cmd[i])
	{
		j = 0;
		while (pipex->cmd[i][j])
		{
			free(pipex->cmd[i][j]);
			j++;
		}
		free(pipex->cmd[i]);
		i++;
	}
	free(pipex->cmd);
}

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


t_boolean	core(t_pipex *pipex)
{
	int		i;
	pid_t	pid;

	i = -1;
	if (pipex->here_doc == true)
		here_doc(pipex);
	else
	{
		if (dup2(pipex->input_fd, STDIN_FILENO) == -1)
			return (free_all(pipex), false);
		close(pipex->input_fd);
	}
	while (++i < pipex->fork_count)
	{
		if (pipe(pipex->pipe_fd) == -1)
			return (free_all(pipex), false);
		pid = fork();
		if (pid == -1)
			return (free_all(pipex), false);
		if (!fork_process(pipex, pid, i))
			return (free_all(pipex), false);
	}
	while (wait(NULL) != -1)
		;
	free_all(pipex);
	close(pipex->outfile_fd);
	return (true);
}

t_boolean	open_files(t_pipex *pipex)
{
	if (pipex->here_doc == true)
	{
		pipex->outfile_fd = open(pipex->av[pipex->ac - 1],
				O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (pipex->outfile_fd == -1)
			return (false);
	}
	else
	{
		pipex->input_fd = open(pipex->av[1], O_RDONLY);
		pipex->outfile_fd = open(pipex->av[pipex->ac - 1],
				O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (pipex->input_fd < 0 || pipex->outfile_fd < 0)
			return (false);
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
	}
}
