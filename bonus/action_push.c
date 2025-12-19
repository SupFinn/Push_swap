/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 04:44:18 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/19 04:02:05 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	if (!src || !*src)
		return (0);
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dst;
	*dst = tmp;
	return (1);
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
}

void	pb(t_list **b, t_list **a)
{
	push(b, a);
}
