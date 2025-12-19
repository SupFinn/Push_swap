/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:30:37 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/19 14:35:17 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	execute_instructions(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		apply_instruction(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

void	check_final_state(t_list *a, t_list *b)
{
	t_list	*tmp;

	if (b != NULL)
	{
		write(1, "KO\n", 3);
		return ;
	}
	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
		{
			write(1, "KO\n", 3);
			return ;
		}
		tmp = tmp->next;
	}
	write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;

	a = NULL;
	b = NULL;
	init_checker_stacks(&a, &b, argc, argv);
	execute_instructions(&a, &b);
	check_final_state(a, b);
	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
	while (b)
	{
		tmp = b;
		b = b->next;
		free(tmp);
	}
	return (0);
}
