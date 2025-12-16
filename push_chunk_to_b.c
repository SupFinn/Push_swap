/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:40:30 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/16 15:39:00 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk(int index, int chunk_size)
{
	return ((index / chunk_size) + 1);
}

int	search_chunk(t_list **stack, int chunk_size, int current_chunk)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (get_chunk(tmp->index, chunk_size) == current_chunk)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int find_best_move(t_list *stack, int chunk_size, int current_chunk)
{
    int first_pos;
    int last_pos;
    int pos;
    int size;
    t_list *tmp;

	first_pos = -1;
	last_pos = -1;
	pos = 0;
	size = ft_lstsize(stack);
	tmp = stack;
    while (tmp)
    {
        if (get_chunk(tmp->index, chunk_size) == current_chunk)
        {
            if (first_pos == -1)
                first_pos = pos;
            last_pos = pos;
        }
        tmp = tmp->next;
        pos++;
    }
    if (first_pos <= (size - last_pos))
        return (first_pos);
    return (last_pos);
}

void push_chunk_to_b(t_list **stack_a, t_list **stack_b,
            int chunk_size, int current_chunk)
{
    int     target_pos;
    int     target_index;
    t_list  *tmp;
    int     i;

    while (search_chunk(stack_a, chunk_size, current_chunk))
    {
        target_pos = find_best_move(*stack_a, chunk_size, current_chunk);
        tmp = *stack_a;
        i = 0;
        while (i < target_pos)
        {
            tmp = tmp->next;
            i++;
        }
        target_index = tmp->index;
        bring_to_top(stack_a, target_index, 'a');
        pb(stack_b, stack_a);
        if (ft_lstsize(*stack_b) > 1 && 
            (*stack_b)->index < (current_chunk * chunk_size - (chunk_size / 2)))
            rb(stack_b);
    }
}
