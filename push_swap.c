/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:51:29 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/16 09:32:17 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(int argc, char **argv, t_list **stack_a)
{
	if (argc < 2)
		return (1);
	if (argc == 2)
		build_stack(stack_a, ft_split(argv[1], ' '), 1);
	else if (argc > 2)
		build_stack(stack_a, argv + 1, 0);
	return (0);
}

int	is_sorted(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_whole_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (size == 2)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa (stack_a);
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4 || size == 5)
		sort_small_stack(stack_a, stack_b);
	else
		sort_large_stack(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (parse_input(argc, argv, &stack_a))
		return (0);
	if (has_duplicates(stack_a))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	assign_indexes (stack_a);
	sort_whole_stack(&stack_a, &stack_b);
	return (0);
}
