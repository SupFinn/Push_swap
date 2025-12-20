/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:29:47 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/20 04:42:47 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_list *stack, int index)
{
	int		pos;
	t_list	*tmp;

	pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index == index)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	calculate_moves(t_list *a, t_list *b, int b_index)
{
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;
	int	target;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	target = get_target_index(a, b_index);
	pos_a = get_position(a, target);
	pos_b = get_position(b, b_index);
	if (pos_a <= size_a / 2 && pos_b <= size_b / 2)
		return (max(pos_a, pos_b));
	if (pos_a > size_a / 2 && pos_b > size_b / 2)
	{
		pos_a = size_a - pos_a;
		pos_b = size_b - pos_b;
		return (max(pos_a, pos_b));
	}
	if (pos_a > size_a / 2)
		pos_a = size_a - pos_a;
	if (pos_b > size_b / 2)
		pos_b = size_b - pos_b;
	return (pos_a + pos_b);
}
