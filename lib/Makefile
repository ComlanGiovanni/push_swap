# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 08:46:58 by gcomlan           #+#    #+#              #
#    Updated: 2022/07/09 23:43:11 by gcomlan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpushswap.a

CC = gcc -Wall -Wextra -Werror

#normal not fd after
SRC =  	ft_atoi.c \
		ft_atol.c \
		ft_free_tab.c \
		ft_isdigit.c \
		ft_split.c \
		ft_strjoin.c \
		ft_strdup.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_putchar.c \
		ft_strcmp.c \
		ft_isspace.c \
		ft_putnbr.c \
		ft_strchr.c

BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m
NO_COLOR		=	\033[0m

COMP_START	=	echo "\n🚧 $(PURPLE)Make lib : $(NO_COLOR)Starting the compilation of *.o...\n"

CLEANED		=	echo "\n💧 $(GREEN)Clean lib: $(NO_COLOR)Removed all the \".o\" files 🗑\\n"

FCLEANED	=	echo "\n🧼 $(GREEN)Fclean lib: $(NO_COLOR)Removed the executables 🗑\\n"

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(COMP_START)
	ar rc $(NAME) $(OBJS)

clean :
	@$(CLEANED)
	rm -f $(OBJS)

fclean : clean
	@$(FCLEANED)
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
