/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:58:38 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/09 10:49:22 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	build_stack(t_list **stack, char **numbers)
{
	int		i;
	int 	value;
	t_list	*node;

	i = 0;
	while (numbers[i])
	{
		value = ft_atoi(numbers[i]);
		node = new_node(value);
		add_back(stack, node);
		i++;
	}
}
