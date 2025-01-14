/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:11:34 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/14 03:42:36 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_shell(t_pipex *pipex, char **path, char *slash, int i)
{
	char	*tester;
	int		checker;
	int		j;

	j = 0;
	while (path[j])
	{
		tester = ft_strjoin(path[j], slash);
		checker = access(tester, F_OK);
		if (checker == 0)
		{
			execve(tester, pipex->cmd[i], pipex->env);
			perror("execve");
			free(tester);
			exit(EXIT_FAILURE);
		}
		free(tester);
		j++;
	}
	return (checker);
}

int	env_exec(t_pipex *pipex, int i)
{
	char	*slash;
	int		status;

	printf("IVI%s\n", pipex->cmd[i][0]);
	slash = ft_strjoin("/", pipex->cmd[i][0]);
	printf("IVI%s\n", slash);
	status = exec_shell(pipex, pipex->env_path, slash, i);
	free(slash);
	if (status == -1)
		return (error_handler(2));
	return (0);
}
