/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <444nt000@proton.me>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:19:15 by aradix            #+#    #+#             */
/*   Updated: 2026/11/03 16:22:15 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(tmp, del);
	}
	*lst = NULL;
}
