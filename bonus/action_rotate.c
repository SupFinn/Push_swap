/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:23:00 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/19 04:02:24 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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

void	ra(t_list **a)
{
	rotate(a);
}

void	rb(t_list **b)
{
	rotate(b);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}
