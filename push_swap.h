/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:47:51 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/16 23:53:22 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_list
{
	int					value;
	int					index;
	struct s_list		*next;
}	t_list;

int		is_digit(char c);
int		is_valid_number(const char *str);
int		has_duplicates(t_list *stack);
int		safe_atoi(const char *str, int *out);
int		parse_input(int argc, char **argv, t_list **stack_a);

size_t	ft_strlen(const char *str);
size_t	ft_lstsize(t_list *lst);
t_list	*new_node(int value);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

void	add_front(t_list **stack, t_list *new);
void	add_back(t_list **stack, t_list *new);
void	build_stack(t_list **stack, char **numbers, int free_after);
void	assign_indexes(t_list *stack);
void	bring_to_top(t_list **stack_a, int index, char stack_name);
void	sort_three(t_list **stack_a);
void	sort_small_stack(t_list **stack_a, t_list **stack_b);
void	sort_whole_stack(t_list **stack_a, t_list **stack_b);
void	sort_large_stack(t_list **stack_a, t_list **stack_b);
void	push_chunk_to_b(t_list **stack_a, t_list **stack_b, \
		int chunk_size, int current_chunk);

void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif
