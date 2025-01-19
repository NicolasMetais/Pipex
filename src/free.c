/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:32:18 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/19 22:19:57 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
