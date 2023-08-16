/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:05:38 by ldeville          #+#    #+#             */
/*   Updated: 2023/02/11 12:47:08 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*rlst;

	if (!lst)
		return (NULL);
	nlst = ft_lstnew((*f)(lst->content));
	if (!nlst)
		return (NULL);
	rlst = nlst;
	lst = lst->next;
	while (lst)
	{
		nlst->next = ft_lstnew((*f)(lst->content));
		if (!lst->content)
		{
			ft_lstclear(&rlst, del);
			return (NULL);
		}
		lst = lst->next;
		nlst = nlst->next;
	}
	return (rlst);
}
