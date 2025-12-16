/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 00:39:34 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/16 03:39:41 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	if ((*stack_a)->index == 2)
		ra (stack_a);
	else if ((*stack_a)->next->index == 2)
		rra (stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa (stack_a);
}

void	sort_small_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	bring_to_top(&stack_a, 0);
	pb(stack_b, stack_a);
	if (size == 5)
	{
		bring_to_top(&stack_a, 1);
		pb(stack_b, stack_a);
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	if (size == 5)
		pa(stack_a, stack_b);
}
