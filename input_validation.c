/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:07:18 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/15 18:29:01 by rhssayn          ###   ########.fr       */
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

int	safe_atoi(const char *str, int *out)
{
	long	result;
	int 	sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (!is_valid_number(str))
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ((str[i]) >= '0' && str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN))
			return (0);
		i++;
	}
	*out = ((int)result) * sign;
	return (1);
}
