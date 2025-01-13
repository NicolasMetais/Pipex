/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:34:09 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:03:00 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*elem;

	if (lst)
	{
		elem = *lst;
		while (elem)
		{
			next = elem->next;
			ft_lstdelone(elem, (del));
			elem = next;
		}
		*lst = NULL;
	}
}
