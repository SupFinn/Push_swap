/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 04:05:27 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/19 14:32:21 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				in_lis;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strncpy(char *dest, char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *str);

t_list				*new_node(int value);
size_t				ft_lstsize(t_list *lst);
void				add_front(t_list **stack, t_list *new);
void				add_back(t_list **stack, t_list *new);
void				build_stack(t_list **stack, char **numbers);
void				assign_indexes(t_list *stack);
int					has_duplicates(t_list *stack);

void				init_checker_stacks(t_list **a, t_list **b, int argc,
						char **argv);
int					execute_instructions(t_list **a, t_list **b);
void				apply_instruction(char *line, t_list **a, t_list **b);
void				check_final_state(t_list *a, t_list *b);
void				bad_operation(char *line);

int					push(t_list **dst, t_list **src);
void				pa(t_list **a, t_list **b);
void				pb(t_list **b, t_list **a);

int					swap(t_list **lst);
void				sa(t_list **a);
void				sb(t_list **b);
void				ss(t_list **a, t_list **b);

int					rotate(t_list **lst);
void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);

int					reverse(t_list **lst);
void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);

#endif
