/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:40:30 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/15 09:55:11 by rhssayn          ###   ########.fr       */
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

void	push_chunk_to_b(t_list **stack_a, t_list **stack_b,
			int chunk_size, int current_chunk)
{
	while (search_chunk(stack_a, chunk_size, current_chunk))
	{
		if (get_chunk(stack_a->index, chunk_size) == current_chunk)
			pb (stack_b, stack_a);
		else
			ra (stack_a);
	}
}
