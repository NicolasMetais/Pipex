/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:11:34 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/19 18:31:14 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_boolean	exec_shell(t_pipex *pipex, char **path, char *slash, int i)
{
	char	*tester;
	int		checker;
	int		j;

	j = 0;
	while (path[j])
	{
		tester = ft_strjoin(path[j], slash);
		if (!tester)
			return (false);
		checker = access(tester, F_OK);
		if (checker == 0)
		{
			free(slash);
			if (execve(tester, pipex->cmd[i], pipex->env) == -1)
				return (free(tester), false);
			perror("");
			exit(EXIT_FAILURE);
		}
		free(tester);
		j++;
	}
	free(slash);
	return (false);
}

int	env_exec(t_pipex *pipex, int i)
{
	char	*slash;
	int		status;

	slash = ft_strjoin("/", pipex->cmd[i][0]);
	if (!slash)
		return (false);
	status = exec_shell(pipex, pipex->env_path, slash, i);
	perror("");
	free(slash);
	if (status == -1)
		return (error_handler(2));
	return (0);
}
