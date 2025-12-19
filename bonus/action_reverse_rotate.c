/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_reverse_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:21:54 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/19 04:02:13 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	reverse(t_list **lst)
{
	t_list	*last;
	t_list	*prev;

	if (!(*lst) || !(*lst)->next)
		return (0);
	last = *lst;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = *lst;
	prev->next = NULL;
	*lst = last;
	return (1);
}

void	rra(t_list **a)
{
	reverse(a);
}

void	rrb(t_list **b)
{
	reverse(b);
}

void	rrr(t_list **a, t_list **b)
{
	reverse(a);
	reverse(b);
}
