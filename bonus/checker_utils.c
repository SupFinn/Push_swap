/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 02:31:27 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/19 17:05:41 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned int)s1[i] - (unsigned int)s2[i]);
}

void	init_checker_stacks(t_list **a, t_list **b, int argc, char **argv)
{
	if (argc < 2)
		return ;
	*a = NULL;
	*b = NULL;
	build_stack(a, &argv[1]);
	assign_indexes(*a);
	if (has_duplicates(*a))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	bad_operation(char *line)
{
	write(2, "Error\n", 6);
	free(line);
	exit(1);
}

void	apply_instruction(char *line, t_list **a, t_list **b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a, 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b, 0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(b, a, 0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a, 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b, 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a, 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b, 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	else
		bad_operation(line);
}
