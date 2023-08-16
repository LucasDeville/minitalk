/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:46:20 by ldeville          #+#    #+#             */
/*   Updated: 2023/02/10 15:56:26 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include  "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*inlst;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	inlst = *lst;
	while (inlst->next)
		inlst = inlst->next;
	inlst->next = new;
}
