/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:13:50 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/18 22:46:52 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	is_in_lis(int value, int *lis, int lis_length)
{
	int	i;

	i = 0;
	while (i < lis_length)
	{
		if (lis[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	sort_large_stack(t_list **stack_a, t_list **stack_b)
{
	int	*lis;
	int	lis_length;
	int	size;

	size = ft_lstsize(*stack_a);
	lis = get_lis(*stack_a, size, &lis_length);
	if (!lis)
		return ;
	while (size > lis_length)
	{
		if (!is_in_lis((*stack_a)->index, lis, lis_length))
		{
			pb(stack_b, stack_a);
			size--;
		}
		else
			ra(stack_a);
	}
	free(lis);
	push_back_to_a(stack_a, stack_b);
}
