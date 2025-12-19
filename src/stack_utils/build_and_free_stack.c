/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_and_free_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:58:38 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/19 21:23:43 by rhssayn          ###   ########.fr       */
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

void	build_stack(t_list **stack, char **numbers)
{
	int		i;
	char	**split;
	int		j;
	int		num;

	i = 0;
	while (numbers[i])
	{
		split = ft_split(numbers[i], ' ');
		j = 0;
		while (split[j])
		{
			if (!safe_atoi(split[j], &num))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			add_back(stack, new_node(num));
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
}
