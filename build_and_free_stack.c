/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_and_free_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:58:38 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/20 06:40:32 by rhssayn          ###   ########.fr       */
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

void	free_array(char **arr)
{
	int	i = 0;

	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
int	build_stack(t_list **stack, char **numbers)
{
	int i = 0, j, num;
	char **split;
	t_list *node;

	while (numbers[i])
	{
		split = ft_split(numbers[i], ' ');
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			if (!safe_atoi(split[j], &num) || !(node = new_node(num)))
			{
				free_array(split);
				free_stack(stack);
				return (0);
			}
			add_back(stack, node);
			j++;
		}
		free_array(split);
		i++;
	}
	return (1);
}
