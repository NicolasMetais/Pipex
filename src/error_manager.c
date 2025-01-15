/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:32:18 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/15 02:21:26 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_handler(int error)
{
	if (error == 2)
	{
		write(2, "Error\nWrong shell cmd", 21);
		exit(127);
	}
	perror("");
	exit(error);
	return (error);
}