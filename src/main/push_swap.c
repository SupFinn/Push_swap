/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:51:29 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/19 15:12:21 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

static void	start_sort(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 5)
		sort_small_stack(a, b);
	else
		sort_large_stack(a, b);
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
