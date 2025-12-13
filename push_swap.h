/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:47:51 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/13 04:45:23 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define INT_MAX 2147483647

typedef struct s_list
{
	int					value;
	int					index;
	struct s_list		*next;
	struct s_list		*prev;
}	t_list;

int		ft_atoi(const char *str);
int		get_chunk(int index, int chunk_size);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

void	add_front(t_list **stack, t_list *new);
void	add_back(t_list **stack, t_list *new);
void	build_stack(t_list **stack, char **numbers);
void	assign_indexes(t_list *stack);
void	pb(t_list **stack_a, t_list **stack_b);
void	push_chunk_to_b(t_list **stack_a, t_list **stack_b, \
		int chunk_size, int current_chunk);

size_t	ft_strlen(const char *str);

t_list	*new_node(int value);

#endif
