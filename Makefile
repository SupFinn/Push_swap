SRCS = push_swap.c op_push.c op_swap.c op_rotate.c op_reverse_rotate.c \
		bring_to_top.c build_and_free_stack.c stack_utils.c input_validation.c \
		helpers.c sort_small_stack.c sort_large_stack.c push_back_to_a.c moves_utils.c \
		lis_utils.c target_finder.c ft_split.c \

BONUS_SRCS = bonus/checker.c op_swap.c op_rotate.c op_push.c op_reverse_rotate.c \
			 build_and_free_stack.c stack_utils.c input_validation.c helpers.c \
             ft_split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

NAME = push_swap
BONUS_NAME = checker

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

bonus: $(BONUS_NAME)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus

.SECONDARY: $(OBJS) $(BONUS_OBJS)