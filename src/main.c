/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:26:32 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/13 05:11:43 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "unistd.h"
#include <sys/types.h>
#include <sys/wait.h>



void	pipex_init(t_pipex *pipex, int ac, char **av, char **env)
{
	pipex->fork_count = ac - 2;
	pipex->pipe_count = pipex->fork_count - 1;
	while ((ft_strncmp(*env, "PATH=", 5)))
		env++;
	pipex->env = env;
	pipex->av = av;
	pipex->ac = ac;
	pipex->absolute_path = false;
}

void	fd_setup(t_pipex *pipex, int pipe_fd, int i)
{
	if (pipex->input_fd != 0)
	{
		printf("IN\n");
		dup2(pipex->input_fd, STDIN_FILENO);
		close(pipex->input_fd);
	}
	else if (pipe_fd != 1)
	{
		printf("OUT\n");
		dup2(pipe_fd, STDOUT_FILENO);
		close(pipe_fd);
	}
	printf("I %d\n", i);
	env_exec(pipex, i);
	perror("exec");
	exit(EXIT_FAILURE);
}

int	core(t_pipex *pipex)
{
	int		i;
	pid_t	pid;
	int		pipe_fd[2];

	i = 0;
	while (i < pipex->fork_count - 1)
	{
		pipe(pipe_fd);
		pid = fork();
		if (pid == 0) //process enfant
		{
			close(pipe_fd[0]);
			fd_setup(pipex, pipe_fd[1], i);
		}
		else //process parent
		{
			close(pipe_fd[1]);
			if (pipex->input_fd != 0)
				close(pipex->input_fd);
			pipex->input_fd = pipe_fd[0];
		}
		i++;
	}
	int status;
	while (wait(&status) != -1);
	return (0);
	//derniere commande ici a injecter dans le fichier
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
		if (env_parse(&pipex) == false)
			return (0);
		//env_exec(&pipex, 0);
		core(&pipex);
	}
}
