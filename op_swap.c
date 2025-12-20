/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:47:19 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/19 22:45:10 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sa(t_list **a, int print)
{
	if (swap(a) && print)
		write(1, "sa\n", 3);
}

void	sb(t_list **b, int print)
{
	if (swap(b) && print)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, int print)
{
	if (swap(a) && swap(b) && print)
		write(1, "ss\n", 3);
}
