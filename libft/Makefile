# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 18:13:30 by anclarma          #+#    #+#              #
#    Updated: 2022/06/17 08:14:20 by bschoeff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ################################## #
#               COMMAND              #
# ################################## #
CC			= gcc
MKDIR		= mkdir -p
RM			= rm -rf
AR			= ar -rc

# ################################## #
#              LIB NAME              #
# ################################## #
NAME		= libft.a

# ################################## #
#               SOURCES              #
# ################################## #
C_DIR		= .
C_FILES		= ft_atoi.c	\
			  ft_calloc.c	\
			  ft_isascii.c	\
			  ft_bzero.c	\
			  ft_isalnum.c	\
			  ft_isalpha.c	\
			  ft_isdigit.c	\
			  ft_isprint.c	\
			  ft_memchr.c	\
			  ft_memcmp.c	\
			  ft_memcpy.c	\
			  ft_strdup.c	\
			  ft_memmove.c	\
			  ft_memset.c	\
			  ft_strchr.c	\
			  ft_strlcat.c	\
			  ft_strlcpy.c	\
			  ft_strlen.c	\
			  ft_strncmp.c	\
			  ft_strnstr.c	\
			  ft_strrchr.c	\
			  ft_tolower.c	\
			  ft_toupper.c	\
			  ft_substr.c	\
			  ft_strjoin.c	\
			  ft_strtrim.c	\
			  ft_split.c	\
			  ft_itoa.c		\
			  ft_strmapi.c	\
			  ft_striteri.c	\
			  ft_putchar_fd.c	\
			  ft_putstr_fd.c	\
			  ft_putendl_fd.c	\
			  ft_putnbr_fd.c	\
			  ft_printf.c		\
			  ft_printf_helpers.c	\
			  ft_printf_writers.c	\
			  ft_secure_atoi.c	\
			  get_next_line.c	\
			  get_next_line_utils.c	\
			  ft_isspace.c		\
			  ft_lstadd_back.c	\
			  ft_lstadd_front.c	\
			  ft_lstsize.c		\
			  ft_lstlast.c		\
			  ft_lstdelone.c	\
			  ft_lstclear.c		\
			  ft_lstiter.c		\
			  ft_lstmap.c		\
			  ft_lstnew.c
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
CFLAGS		= -Wall -Wextra -Werror -g3
LFLAGS		=
CINCLUDES	=
CLIBS		=

# ################################## #
#                RULES               #
# ################################## #

$(O_DIR)/%.o: $(C_DIR)/%.c
			$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@

all:		$(NAME)

$(NAME):	$(O_DIR) $(OBJS)
			$(AR) $@ $(OBJS)

$(O_DIR):
			$(MKDIR) $(O_DIR)

clean:
			$(RM) $(O_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

-include	$(OBJS:.o=.d)

.PHONY: all check clean fclean re
