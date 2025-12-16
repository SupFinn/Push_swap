/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:51:02 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/16 03:39:22 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_list *stack)
{
	t_list	*tmp;
	int		max;

	if (!stack)
		return (0);
	tmp = stack;
	max = tmp->index;
	while (tmp)
	{
		if (max < tmp->index)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

void	sort_stack_b(t_list **stack_a, t_list **stack_b)
{
	int		max_index;

	while (*stack_b)
	{	
		max_index = find_max_index(*stack_b);
		bring_to_top(&stack_b, max_index);
		pa (stack_a, stack_b);
	}
}
