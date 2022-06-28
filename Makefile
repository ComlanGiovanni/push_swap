# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 14:04:12 by gcomlan           #+#    #+#              #
#    Updated: 2022/06/27 20:25:33 by gcomlan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GCC = gcc -Wall -Wextra -Werror -g3

NAME		=	push_swap

LIB_NAME	=	libpushswap.a

CHECKER_NAME	= checker

RM			= rm -f

#Files
SRC		=	main.c \
			./src/operation/pa_pb.c \
			./src/operation/ra_rb_rr.c \
			./src/operation/rra_rrb_rrr.c \
			./src/operation/sa_sb_ss.c \
			./src/parsing/parsing_arg.c \
			./src/parsing/parsing_str.c \
			./src/sorting/big_stack.c \
			./src/sorting/small_stack.c \
			./src/sorting/small_stack_tools.c \
			./src/sorting/stack_tools.c \
			./src/tools/debug_tools.c \
			./src/tools/linkedlist_tools.c \
			./src/tools/sorting_tools.c

SRCS_BONUS	=   ./bonus/main.c \
            	./bonus/checker.c \
				./bonus/tools.c

#Obj
SRC_OBJS		=	$(SRC:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)


# ------------------------------ Colors ------------------------------

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

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(PURPLE)Make: $(NO_COLOR)Starting the compilation...\n"

PUSH_SWAP_COMP	=	echo "\n🚧 $(YELLOW)push_swap: $(NO_COLOR)Starting the compilation...\n"

PUSH_SWAP_READY	=	echo "\n🧮 $(RED)push_swap $(NO_COLOR)ready!\n"

BONUS_READY	=	echo "\n🎯 Bonus: $(CYAN)checker $(NO_COLOR)ready!\n"

CLEANED		=	echo "\n💧 $(GREEN)Clean: $(NO_COLOR)Removed all the \".o\" files 🗑\\n"

FCLEANED	=	echo "\n🧼 $(GREEN)Fclean: $(NO_COLOR)Removed the executables 🗑\\n"

NEW_LINE	=	echo "\n"

# ------------------------------ Rules ---------------------------------

all : $(NAME)

$(NAME):
	make -C ./lib/
	cp ./lib/libpushswap.a .
	@$(PUSH_SWAP_COMP)
	gcc $(SRC) -L. $(LIB_NAME) -o $(NAME)
	@$(PUSH_SWAP_READY)

bonus: $(OBJS_BONUS)
	make -C ./lib/
	cp ./lib/libpushswap.a ./bonus
	$(GCC) $(OBJS_BONUS) ./bonus/$(LIB_NAME) -o $(CHECKER_NAME)
	@$(BONUS_READY)

clean :
	rm -f *.o
	rm -f *~
	rm -f *#
	$(RM) ./bonus/*.o
	make -C ./lib/ clean
	@$(CLEANED)

fclean : clean
	rm -f $(NAME)
	make -C ./lib/ fclean
	rm -f $(LIB_NAME)
	rm -f ./bonus/$(LIB_NAME)
	rm -f $(CHECKER_NAME)
	@$(FCLEANED)

re : fclean all

.PHONY : all clean fclean re
