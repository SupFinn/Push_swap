/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:23:00 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/19 16:47:25 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	if (!*lst || !(*lst)->next)
		return (0);
	first = *lst;
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = first;
	*lst = first->next;
	first->next = NULL;
	return (1);
}

void	ra(t_list **a, int print)
{
	if (rotate(a) && print)
		write(1, "ra\n", 3);
}

void	rb(t_list **b, int print)
{
	if (rotate(b) && print)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, int print)
{
	if (rotate(a) && rotate(b) && print)
		write(1, "rr\n", 3);
}
