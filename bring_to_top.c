/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 03:36:29 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/16 15:33:15 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	perform_rotation(t_list **stack, char stack_name, int reverse)
{
	if (reverse)
	{
		if (stack_name == 'a')
			rra(stack);
		else
			rrb(stack);
	}
	else
	{
		if (stack_name == 'a')
			ra(stack);
		else
			rb(stack);
	}
}

void	bring_to_top(t_list **stack, int index, char stack_name)
{
	t_list	*tmp;
	int		pos;
	int		size;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	pos = 0;
	size = ft_lstsize(tmp);
	while (tmp && tmp->index != index)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
	{
		while ((*stack)->index != index)
			perform_rotation(stack, stack_name, 0);
	}
	else
	{
		while ((*stack)->index != index)
			perform_rotation(stack, stack_name, 1);
	}
}
