/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 08:29:39 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/18 21:29:22 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

size_t	ft_lstsize(t_list *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	add_back(t_list **stack, t_list *new)
{
	t_list	*tmp;

	tmp = *stack;
	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		new->next = NULL;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

int	is_unindexed(t_list *stack)
{
	while (stack)
	{
		if (stack->index == -1)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	assign_indexes(t_list *stack)
{
	t_list	*tmp;
	t_list	*min_node;
	int		min_value;
	int		index;

	index = 0;
	while (is_unindexed(stack))
	{
		tmp = stack;
		min_node = NULL;
		min_value = INT_MAX;
		while (tmp)
		{
			if (tmp->index == -1 && (min_node == NULL
					|| tmp->value < min_value))
			{
				min_node = tmp;
				min_value = tmp->value;
			}
			tmp = tmp->next;
		}
		min_node->index = index;
		index++;
	}
}
