/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:26:32 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/15 04:48:23 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "unistd.h"
#include <sys/types.h>
#include <sys/wait.h>



void	pipex_init(t_pipex *pipex, int ac, char **av, char **env)
{
	pipex->fork_count = ac - 3;
	pipex->pipe_count = pipex->fork_count - 1;
	while ((ft_strncmp(*env, "PATH=", 5)))
		env++;
	pipex->env = env;
	pipex->av = av;
	pipex->ac = ac;
	pipex->absolute_path = false;
}


void	core(t_pipex *pipex)
{
	int		i;
	pid_t	pid;

	i = 0;
	dup2(pipex->input_fd, STDIN_FILENO);
	close(pipex->input_fd);
	while (i < pipex->fork_count)
	{
		pipe(pipex->pipe_fd);
		pid = fork();
		fork_process(pipex, pid, i);
		i++;
		wait(NULL);
	}
	//while(wait(NULL) > 0);

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
		core(&pipex);
	}
}
