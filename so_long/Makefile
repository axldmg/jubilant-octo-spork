# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 12:36:33 by anclarma          #+#    #+#              #
#    Updated: 2022/06/16 10:50:34 by bschoeff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ################################## #
#               COMMAND              #
# ################################## #
CC			= gcc
MKDIR		= mkdir -p
RM			= rm -rf

# ################################## #
#              EXEC NAME             #
# ################################## #
NAME		= so_long

# ################################## #
#               SOURCES              #
# ################################## #
C_DIR		= src
C_FILES		= compliance.c	\
			  destroy.c		\
			  directions.c	\
			  display.c		\
			  game.c		\
			  initialize.c	\
			  main.c		\
			  parsing.c		\
			  push_tiles.c

SRCS		= $(patsubst %, $(C_DIR)/%, $(C_FILES))

# ################################## #
#               OBJECTS              #
# ################################## #
O_DIR		= objs
O_FILES		= $(C_FILES:.c=.o)
OBJS		= $(patsubst %, $(O_DIR)/%, $(O_FILES))

# ################################## #
#                FLAGS               #
# ################################## #
CFLAGS		= -Wall -Wextra -Werror
LFLAGS		= 
CINCLUDES	= -I ./inc	\
			  -I ./lib/libft \
			  -I ./lib/mlx_linux

LIBFT		= ./lib/libft/libft.a
LIBMLX		= ./lib/mlx_linux/mlx.a
CLIBS		= -L ./lib/libft -lft -L ./lib/mlx_linux -lmlx -lX11 -lXext

# ################################## #
#                RULES               #
# ################################## #

$(O_DIR)/%.o: $(C_DIR)/%.c
			$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@

all:		$(NAME)

check:	fclean
check:	CFLAGS		+=  -pedantic -ansi
check:	CFLAGS		+=  -fsanitize=address
check:	CFLAGS		+=  -fsanitize=leak
check:	CFLAGS		+=  -fsanitize=undefined
check:	CFLAGS		+=  -g3
check:	LFLAGS		+=  -fsanitize=address
check:	LFLAGS		+=  -fsanitize=leak
check:	LFLAGS		+=  -fsanitize=undefined
check:	LFLAGS		+=  -g3
check:	${NAME}

$(NAME):	$(O_DIR) $(LIBFT) $(LIBMLX) $(OBJS)
			$(CC) $(OBJS) $(LFLAGS) $(CLIBS) -o $@

$(O_DIR):
			$(MKDIR) $(O_DIR)

$(LIBFT):
			make -C ./lib/libft
$(LIBMLX) :
			make -C ./lib/mlx_linux

clean:
			$(RM) $(O_DIR)
			make -C ./lib/libft fclean
			make -C ./lib/mlx_linux clean

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

-include	$(OBJS:.o=.d)

.PHONY: all check clean fclean re
