/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:58:38 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/18 20:24:36 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_numbers(t_list **stack, char *str)
{
	char	**split;
	int		i;
	int		num;

	split = ft_split(str, ' ');
	i = 0;
	while (split[i])
	{
		if (!safe_atoi(split[i], &num))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		add_back(stack, new_node(num));
		free(split[i]);
		i++;
	}
	free(split);
}

void	build_stack(t_list **stack, char **numbers, int free_after)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		parse_numbers(stack, numbers[i]);
		i++;
	}
	if (free_after)
	{
		i = 0;
		while (numbers[i])
			free(numbers[i++]);
		free(numbers);
	}
}
