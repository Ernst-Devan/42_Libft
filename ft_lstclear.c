/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:25:29 by dernst            #+#    #+#             */
/*   Updated: 2024/11/12 22:57:52 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *last;

	if (!(*lst))
		return;
		
	while ((*lst)->next != NULL)
	{
		last = ft_lstlast((*lst));
		del(last->content);
		free(last);
		last = NULL;
	}
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
