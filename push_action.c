/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 04:44:18 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/13 05:17:21 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	if (!src || !*src)
		return (0);
	tmp = *src;
	*src = tmp->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dst;
	if (*dst)
		(*dst)->prev = tmp;
	tmp->prev = NULL;
	*dst = tmp;
	return (1);	
}

void	pa(t_list **a, t_list **b)
{
	if (push(a, b))
		write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	if (push(b, a))
		write(1, "pb\n", 3);
}
