SRCS = action_push.c action_reverse_rotate.c action_rotate.c action_swap.c bring_to_top.c build_stack.c \
		ft_lstsize.c ft_split.c ft_strlen.c ft_substr.c input_validation.c push_chunk_to_a.c push_chunk_to_b.c \
		push_swap.c safe_atoi.c sort_three_five.c stack_utils.c

OBJS = $(SRCS:.c=.o)

CC = CC
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS)
		ar -rcs $(NAME) $(OBJS)

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re