# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 18:45:54 by ruchoa            #+#    #+#              #
#    Updated: 2023/02/14 13:49:00 by cnascime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#MAKEFLAGS			=	--silent

NAME				=	push_swap

NAME_BONUS			=	
LIBS				=	$(foreach lib, $(LIBS_LIST),$(LIBS_PATH)$(lib)/)
LIBS_A				=	$(foreach lib, $(LIBS_LIST),$(LIBS_PATH)$(lib)/$(lib).a)
LIBS_PATH			=	./
LIBS_LIST			=	libft

INCLUDE_PATH		=	./

COMPILER			=	cc
CFLAGS				=	-Wall -Wextra -Werror -g -I $(INCLUDE_PATH)

AR					=	ar
AFLAGS				=	rc

REMOVE				=	rm
RFLAGS				=	-drf

SRCS				=	$(addprefix $(SRCS_PATH), $(SRCS_LIST))
SRCS_OBJS			= 	$(SRCS:.c=.o)
SRCS_PATH			=	./
SRCS_LIST			=	push_swap.c parsing.c sorting.c stacking.c \
		swap.c push.c rotate.c reverse.c radix.c

BONUS				=	$(addprefix $(BONUS_PATH), $(BONUS_LIST))
BONUS_OBJS			=	$(BONUS:.c=.o)
BONUS_PATH			=	./
BONUS_LIST			=	c	 \

ARR					=	ARG=$$(seq 500 | sort --random-sort | tr "\n" " ")

ifeq ($(shell uname), Darwin)	#MacOS
	SYSTEM			=	@printf "\e[1;33mMacOS detected.\n\e[m"
	CHECKER			=	checker_Mac
else 							#Linux
	SYSTEM			=	@printf "\e[1;33mLinux detected.\n\e[m"
	CHECKER			=	checker
endif

.c.o:
						$(COMPILER) $(CFLAGS) -c $< -o $(<:.c=.o)

all:					$(NAME)

bonus:					$(NAME_BONUS)

$(NAME):				$(SRCS_OBJS)
						$(foreach lib, $(LIBS), make -C $(lib) ;)
						$(COMPILER) $(CFLAGS) $(SRCS_OBJS) $(LIBS_A) -o $(NAME)

$(NAME_BONUS):			$(BONUS_OBJS) 
						$(foreach lib, $(LIBS), make all -C $(lib) ;)
						$(COMPILER) $(CFLAGS) $(BONUS_OBJS) $(LIBS_A) -o $(NAME_BONUS)

clean:
						$(REMOVE) $(RFLAGS) $(SRCS_OBJS) $(BONUS_OBJS)
						$(foreach lib, $(LIBS), make clean -C $(lib) ;)

fclean:					clean
						$(REMOVE) $(RFLAGS) $(NAME) $(NAME_BONUS)
						$(foreach lib, $(LIBS), make fclean -C $(lib) ;)

re:						fclean all
						$(foreach lib, $(LIBS), make re -C $(lib) ;)

.PHONY:					all clean fclean re visualizer

run:					$(NAME)
						$(ARR) ; ./$(NAME) $$ARG

vrun:					$(NAME)
						$(ARR) ; valgrind --leak-check=full -s -v ./$(NAME) $$ARG | ./checker $$ARG

wc:						$(NAME)
						$(SYSTEM)
						$(ARR) ; ./$(NAME) $$ARG | wc -l

check:					$(NAME)
						$(SYSTEM)
						$(ARR) ; ./$(NAME) $$ARG | ./$(CHECKER) $$ARG

rerun:					re run

b:						$(NAME_BONUS)
#						valgrind --leak-check=full -s ./$(NAME_BONUS) $(ARG)
						$(SYSTEM)
						$(ARG) ; ./$(NAME_BONUS) $$VAR
						$(REMOVE) $(RFLAGS) $(NAME_BONUS)

SIZE	=	5
COUNT	=	10
test:					$(NAME)
						bash ./tester/tester.sh ../$(NAME) $(SIZE) $(COUNT)

tall:					$(NAME)
						bash ./tester/tester.sh ../$(NAME) 3 $(COUNT)
						bash ./tester/tester.sh ../$(NAME) 5 $(COUNT)
						bash ./tester/tester.sh ../$(NAME) 100 $(COUNT)
						bash ./tester/tester.sh ../$(NAME) 500 $(COUNT)

visualizer:				$(NAME)
						./visualizer_linux_amd64
