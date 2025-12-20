/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:47:51 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/20 06:44:30 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define BUFFER_SIZE 1024

typedef struct s_list
{
	int				value;
	int				index;
	int				in_lis;
	struct s_list	*next;
}	t_list;

int		is_digit(char c);
int		is_valid_number(const char *str);
int		has_duplicates(t_list *stack);
int		safe_atoi(const char *str, int *out);
int		get_position(t_list *stack, int index);
int		is_sorted(t_list *stack);
int		max(int a, int b);
int		calculate_moves(t_list *a, t_list *b, int b_index);
int		get_target_index(t_list *stack_a, int value);
int		is_unindexed(t_list *stack);
int		is_sorted(t_list *stack);
int		*get_lis(t_list *stack, int size, int *lis_length);
int		build_stack(t_list **stack, char **numbers);

void	push_back_to_a(t_list **stack_a, t_list **stack_b);
void	free_stack(t_list **stack);
void	add_back(t_list **stack, t_list *new);
void	assign_indexes(t_list *stack);
void	bring_to_top(t_list **stack_a, int index, char stack_name);
void	sort_large_stack(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a);
void	sort_small_stack(t_list **stack_a, t_list **stack_b);

size_t	ft_strlen(const char *str);
size_t	ft_lstsize(t_list *lst);

t_list	*new_node(int value);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

void	final_rotate(t_list **stack_a);

// Operations

void	pa(t_list **a, t_list **b, int print);
void	pb(t_list **b, t_list **a, int print);

void	sa(t_list **a, int print);
void	sb(t_list **b, int print);
void	ss(t_list **a, t_list **b, int print);

void	ra(t_list **a, int print);
void	rb(t_list **b, int print);
void	rr(t_list **a, t_list **b, int print);

void	rra(t_list **a, int print);
void	rrb(t_list **b, int print);
void	rrr(t_list **a, t_list **b, int print);

// Bonus

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strncpy(char *dest, char *src, size_t n);

void	bad_operation(char *line);
void	apply_instruction(char *line, t_list **a, t_list **b);
void	init_checker_stacks(t_list **a, t_list **b, int argc,
			char **argv);	

int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif