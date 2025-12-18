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
       src/helpers/ft_split.c \
       src/helpers/ft_substr.c \
       src/helpers/ft_strlen.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re