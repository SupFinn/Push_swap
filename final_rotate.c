/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 20:49:50 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/17 20:50:50 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest_index(t_list *stack)
{
	t_list	*tmp;
	int		min;
	int		min_index;

	tmp = stack;
	min = INT_MAX;
	min_index = -1;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (min_index);
}

void	final_rotate(t_list **stack_a)
{
	int	smallest_index;
	int	pos;
	int	size;

	if (!stack_a || !*stack_a)
		return ;
	smallest_index = find_smallest_index(*stack_a);
	pos = get_position(*stack_a, smallest_index);
	size = ft_lstsize(*stack_a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(stack_a);
	}
	else
	{
		while (pos++ < size)
			rra(stack_a);
	}
}
