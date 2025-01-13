/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:50:48 by nmetais           #+#    #+#             */
/*   Updated: 2024/12/01 00:03:12 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*curr;

	if (!lst || !f || !del)
		return (NULL);
	start = ft_lstnew(f(lst->content));
	curr = start;
	while (lst && lst->next)
	{
		if (!curr)
			return (NULL);
		curr->next = ft_lstnew(f(lst->next->content));
		curr = curr->next;
		lst = lst->next;
	}
	return (start);
}
