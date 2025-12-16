/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 03:36:29 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/16 03:38:07 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_to_top(t_list **stack_a, int index)
{
	t_list *tmp;
	int		pos;
	int		size;
	
	if (!stack_a || !*stack_a)
    	return ;
	tmp = *stack_a;
	pos = 0;
	size = ft_lstsize(tmp);
	while (tmp && tmp->index != index)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
	{
    	while ((*stack_a)->index != index)
        	ra(stack_a);
	}
	else
	{
    	while ((*stack_a)->index != index)
        	rra(stack_a);
	}
}
