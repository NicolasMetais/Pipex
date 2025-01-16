/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:26:32 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/16 05:35:10 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "unistd.h"



void	pipex_init(t_pipex *pipex, int ac, char **av, char **env)
{
	pipex->dup = env;
	while ((ft_strncmp(*env, "PATH=", 5)))
		env++;
	pipex->env = env;
	pipex->cmd = NULL;
	pipex->av = av;
	pipex->ac = ac;
	pipex->here_doc = false;
}


void	core(t_pipex *pipex)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (pipex->here_doc == true)
		here_doc(pipex);
	else
	{
		dup2(pipex->input_fd, STDIN_FILENO);
		close(pipex->input_fd);
	}
	while (i < pipex->fork_count)
	{
		pipe(pipex->pipe_fd);
		pid = fork();
		fork_process(pipex, pid, i);
		i++;
	}
	while (wait(NULL) != -1)
		;
}

void	open_files(t_pipex *pipex)
{
	if (pipex->here_doc == true)
		pipex->outfile_fd = open(pipex->av[pipex->ac - 1],
				O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
	{
		pipex->input_fd = open(pipex->av[1], O_RDONLY);
		pipex->outfile_fd = open(pipex->av[pipex->ac - 1],
				O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	int		input_fd;

	input_fd = 0;
	pipex.input_fd = input_fd;
	if (ac > 4)
	{
		pipex_init(&pipex, ac, av, env);
		if (args_parse(&pipex) != true)
			return (0);
		open_files(&pipex);
		if (env_parse(&pipex) == false)
			return (0);
		core(&pipex);
	}
}
