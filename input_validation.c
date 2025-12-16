/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:07:18 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/16 08:38:26 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (!is_digit(str[i + 1]))
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_list *stack)
{
	t_list	*curr;
	int		num;

	while (stack)
	{
		num = stack->value;
		curr = stack->next;
		while (curr)
		{
			if (curr->value == num)
				return (1);
			curr = curr->next;
		}
		stack = stack->next;
	}
	return (0);
}
