/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:58:38 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/16 08:38:15 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	build_stack(t_list **stack, char **numbers, int free_after)
{
	int		i;
	int		num;

	i = 0;
	while (numbers[i])
	{
		if (!safe_atoi(numbers[i], &num))
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		add_back(stack, new_node(num));
		i++;
	}
	if (free_after)
	{
		i = 0;
		while (numbers[i])
			free (numbers[i++]);
		free (numbers);
	}
}
