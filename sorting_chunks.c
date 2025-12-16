/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_chunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 00:39:34 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/16 20:59:26 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_list **stack_a)
{
    int	first;
    int	second; 
    int	third;
	 
	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
    if (first > second && second < third && first < third)
        sa(stack_a);
    else if (first > second && second > third)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (first > second && second < third && first > third)
        ra(stack_a);
    else if (first < second && second > third && first < third)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (first < second && second > third && first > third)
        rra(stack_a);
}

void	sort_small_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	bring_to_top(stack_a, 0, 'a');
	pb(stack_b, stack_a);
	if (size == 5)
	{
		bring_to_top(stack_a, 1, 'a');
		pb(stack_b, stack_a);
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	if (size == 5)
		pa(stack_a, stack_b);
}

void	sort_large_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	chunk_size;
	int	current_chunk;

	size = ft_lstsize(*stack_a);
	if (size <= 100)
		chunk_size = 15;
	else if (size > 100)
		chunk_size = 50;
	current_chunk = 1;
	while (search_chunk(stack_a, chunk_size, current_chunk))
	{
		push_chunk_to_b(stack_a, stack_b, chunk_size, current_chunk);
		current_chunk++;
	}
	sort_stack_b(stack_a, stack_b);
}