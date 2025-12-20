/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:47:01 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/20 04:27:03 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_best_move(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;
	int		min_moves;
	int		moves;
	int		best_index;

	tmp = stack_b;
	min_moves = INT_MAX;
	best_index = -1;
	while (tmp)
	{
		moves = calculate_moves(stack_a, stack_b, tmp->index);
		if (moves < min_moves)
		{
			min_moves = moves;
			best_index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (best_index);
}

void	do_double_rotations(t_list **a, t_list **b, int b_index, int target)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	while ((*b)->index != b_index && (*a)->index != target && get_position(*b,
			b_index) <= size_b / 2 && get_position(*a, target) <= size_a / 2)
		rr(a, b, 1);
	while ((*b)->index != b_index && (*a)->index != target && get_position(*b,
			b_index) > size_b / 2 && get_position(*a, target) > size_a / 2)
		rrr(a, b, 1);
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int	b_index;
	int	target;

	while (*stack_b)
	{
		b_index = get_best_move(*stack_a, *stack_b);
		target = get_target_index(*stack_a, b_index);
		do_double_rotations(stack_a, stack_b, b_index, target);
		bring_to_top(stack_b, b_index, 'b');
		bring_to_top(stack_a, target, 'a');
		pa(stack_a, stack_b, 1);
	}
}
