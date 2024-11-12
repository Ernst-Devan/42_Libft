/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:04:05 by dernst            #+#    #+#             */
/*   Updated: 2024/11/12 21:17:53 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *head;
	t_list *new;
	head = NULL;

	while (!lst->next)
	{
		new = ft_lstnew(f(lst->content));
		ft_lstadd_back(&head, new);
		lst = lst -> next;
		del(lst->content);
	}
	return (head);
}