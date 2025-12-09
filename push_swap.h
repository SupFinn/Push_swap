/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:47:51 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/09 11:06:05 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int					value;
	int					index;
	struct s_list		*next;
	struct s_list		*prev;
}	t_list;

int		ft_atoi(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

void	add_front(t_list **stack, t_list *new);
void	add_back(t_list **stack, t_list *new);
void	build_stack(t_list **stack, char **numbers);
void	assign_indexes(t_list *stack);

t_node	*new_node(int value);

#endif
