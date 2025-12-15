/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:51:29 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/15 14:22:24 by rhssayn          ###   ########.fr       */
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
	if (first < second && second < third)
		return ;
	else if (first > second && second < third && first < third)
		sa (stack_a);
	else if (second > third)
	{
		sa (stack_a);
		ra (stack_a);
	}
}

void	sort_small_stack(t_list **stack_a, t_list **stack_b)
{
	int		size;

	size = ft_lstsize(*stack_a);
	assign_indexes(*stack_a);
	if (size == 2)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa (*stack_a);
	}
	else if (size == 3)
	{
		
	}
	else if (size == 4 || size == 5)
	{
		
	}
}
