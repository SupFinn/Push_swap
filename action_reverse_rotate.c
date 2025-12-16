/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:21:54 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/14 22:30:55 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (reverse(a))
		write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	if (reverse(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	if (reverse(a) && reverse(b))
		write(1, "rrr\n", 4);
}
