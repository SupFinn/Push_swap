/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:30:37 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/20 06:49:54 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	build_checker_stacks(t_list **a, t_list **b, int argc, char **argv)
{
	if (argc < 2)
		return ;
	*a = NULL;
	*b = NULL;
	if (!build_stack(a, &argv[1]) || has_duplicates(*a))
	{
		write(2, "Error\n", 6);
		free_stack(a);
		exit(1);
	}
	assign_indexes(*a);
}

void	bad_operation(char *line)
{
	write(2, "Error\n", 6);
	free(line);
	free_stack(a);
	free_stack(b);
	exit(1);
}

void	apply_instruction(char *line, t_list **a, t_list **b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(a, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(b, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b, 0);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(b, a, 0);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(a, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(b, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(a, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b, 0);
	else
		bad_operation(line);
}

void	execute_instructions(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		apply_instruction(line, a, b);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	build_checker_stacks(&a, &b, argc, argv);
	execute_instructions(&a, &b);
	if (b || !is_sorted(a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
