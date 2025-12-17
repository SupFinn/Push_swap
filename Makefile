SRCS = push_swap.c stack_utils.c ft_lstsize.c ft_split.c ft_substr.c \
       ft_strlen.c safe_atoi.c input_validation.c build_stack.c \
       action_push.c action_swap.c op_rotate.c action_reverse_rotate.c \
       bring_to_top.c lis_sort.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re