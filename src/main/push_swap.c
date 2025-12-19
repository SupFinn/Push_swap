/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:51:29 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/19 21:23:48 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	start_sort(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 5)
		sort_small_stack(a, b);
	else
		sort_large_stack(a, b);
}

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
			ra(stack_a, 1);
	}
	else
	{
		while (pos++ < size)
			rra(stack_a, 1);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	build_stack(&stack_a, &argv[1]);
	assign_indexes(stack_a);
	if (has_duplicates(stack_a))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		exit (0);
	}
	start_sort(&stack_a, &stack_b);
	final_rotate(&stack_a);
	free_stack(&stack_a);
	return (0);
}
