/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:47:19 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/19 04:02:54 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	swap(t_list **lst)
{
	t_list	*node1;
	t_list	*node2;

	if (!*lst || !(*lst)->next)
		return (0);
	node1 = *lst;
	node2 = node1->next;
	node1->next = node2->next;
	node2->next = node1;
	*lst = node2;
	return (1);
}

void	sa(t_list **a)
{
	swap(a);
}

void	sb(t_list **b)
{
	swap(b);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}
