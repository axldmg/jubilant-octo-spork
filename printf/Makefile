SRC			= $(wildcard *.c)

OBJ			= $(SRC:.c=.o)

CFLAGS		= -Wall -Wextra -Werror
CC			= gcc

NAME		= libftprintf.a

all				: $(NAME)

$(NAME)			: $(OBJ)
		ar -rc $(NAME) $(OBJ)

%.o				: %.c
		$(CC) $(CFLAGS) -c $< -I .

clean			:
		rm -rf $(OBJ)

fclean			: clean
		rm -rf $(NAME)

re				: fclean all

.PHONY : all clean fclean re .c.o
