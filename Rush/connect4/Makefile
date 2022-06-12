# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 12:36:33 by anclarma          #+#    #+#              #
#    Updated: 2022/06/12 15:39:03 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ################################## #
#               COMMAND              #
# ################################## #
CC			= cc
MKDIR		= mkdir -p
RM			= rm -rf

# ################################## #
#              EXEC NAME             #
# ################################## #
NAME		= connect4

# ################################## #
#               SOURCES              #
# ################################## #
C_DIR		= src
C_FILES		= main.c	\
			  parsing.c	\
			  display.c	\
			  ai.c		\
			  player.c	\
			  game.c	\
			  eval.c
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
CFLAGS		= -Wall -Wextra -Werror -MMD -MP
LFLAGS		= 
CINCLUDES	= -I ./inc	\
			  -I ./libft
LIBFT		= libft/libft.a
CLIBS		= -L ./libft -lft

# ################################## #
#                RULES               #
# ################################## #

$(O_DIR)/%.o: $(C_DIR)/%.c
			$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@

all:		$(NAME)

$(NAME):	$(O_DIR) $(LIBFT) $(OBJS)
			$(CC) $(OBJS) $(LFLAGS) $(CLIBS) -o $@

$(O_DIR):
			$(MKDIR) $(O_DIR)

$(LIBFT):
			make -C libft all

clean:
			$(RM) $(O_DIR)
			make -C libft fclean

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

-include	$(OBJS:.o=.d)

.PHONY: all clean fclean re
