/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 04:44:18 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/20 18:13:47 by rhssayn          ###   ########.fr       */
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
	tmp->next = *dst;
	*dst = tmp;
	return (1);
}

void	pa(t_list **a, t_list **b, int print)
{
	if (push(a, b) && print)
		write(1, "pa\n", 3);
}

void	pb(t_list **b, t_list **a, int print)
{
	if (push(b, a) && print)
		write(1, "pb\n", 3);
}
