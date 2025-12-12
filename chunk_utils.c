/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:40:30 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/12 15:48:16 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_chunk(int index, int chunk_size)
{
	return ((index / chunk_size) + 1);
}

void	push_chunk_to_b(t_list **stack_a, t_list **stack_b,
			int chunk_size, int current_chunk)
{
	
}
