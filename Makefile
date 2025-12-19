SRCS = src/main/push_swap.c \
       src/stack_ops/action_push.c \
       src/stack_ops/action_swap.c \
       src/stack_ops/action_rotate.c \
       src/stack_ops/action_reverse_rotate.c \
       src/stack_ops/bring_to_top.c \
       src/stack_utils/build_stack.c \
       src/stack_utils/stack_utils.c \
       src/stack_utils/input_validation.c \
       src/stack_utils/safe_atoi.c \
       src/sorting/sort_small_stack.c \
       src/sorting/sort_stack.c \
       src/sorting/final_rotate.c \
       src/sorting/push_back_to_a.c \
       src/sorting/moves_utils.c \
       src/sorting/lis_utils.c \
       src/sorting/target_finder.c \
       src/stack_utils/ft_split.c

BONUS_SRCS = bonus/checker.c \
             bonus/checker_utils.c \
             get_next_line/get_next_line.c \
             get_next_line/get_next_line_utils.c \
             src/sorting/moves_utils.c \
             src/sorting/target_finder.c \
             src/stack_ops/action_push.c \
             src/stack_ops/action_swap.c \
             src/stack_ops/action_rotate.c \
             src/stack_ops/action_reverse_rotate.c \
             src/stack_ops/bring_to_top.c \
             src/stack_utils/build_stack.c \
             src/stack_utils/stack_utils.c \
             src/stack_utils/input_validation.c \
             src/stack_utils/safe_atoi.c \
             src/stack_utils/ft_split.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

NAME = push_swap
BONUS_NAME = checker

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
