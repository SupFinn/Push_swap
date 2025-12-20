/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 00:39:34 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/19 16:51:45 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(stack_a, 1);
	else if (first > second && second > third)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a, 1);
}

void	sort_small_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a, 1);
	else if (size == 3)
		sort_three(stack_a);
	else
	{
		bring_to_top(stack_a, 0, 'a');
		pb(stack_b, stack_a, 1);
		if (size == 5)
		{
			bring_to_top(stack_a, 1, 'a');
			pb(stack_b, stack_a, 1);
		}
		sort_three(stack_a);
		pa(stack_a, stack_b, 1);
		if (size == 5)
			pa(stack_a, stack_b, 1);
	}
}
