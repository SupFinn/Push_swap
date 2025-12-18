/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:38:30 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/18 02:28:09 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_smallest_greater(t_list *stack, int index)
{
    t_list *tmp;
    int target;
    int min_index;

    tmp = stack;
    target = INT_MAX;
    min_index = -1;
    while (tmp)
    {
        if (tmp->index > index && tmp->index < target)
        {
            target = tmp->index;
            min_index = tmp->index;
        }
        tmp = tmp->next;
    }
    return (min_index);
}

static int find_smallest(t_list *stack)
{
    t_list *tmp;
    int min_index;

    tmp = stack;
    min_index = INT_MAX;
    while (tmp)
    {
        if (tmp->index < min_index)
            min_index = tmp->index;
        tmp = tmp->next;
    }
    return (min_index);
}

int get_target_index(t_list *stack_a, int index)
{
    int target;

    target = find_smallest_greater(stack_a, index);
    if (target == -1)
        target = find_smallest(stack_a);
    return (target);
}
