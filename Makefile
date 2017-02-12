##
## Makefile for MALLOC in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Wed Jan 25 20:56:18 2017 bougon_p
## Last update Sun Feb 12 20:19:21 2017 bougon_p
##

DEBUG	= NO



# Color variables

BLUE	= \033[1;34m

WHITE   = \033[0m

RED	= \033[1;31m



# Sources variables

SRC	= 	malloc.c		\
		calloc.c		\
		malloc_utilities.c	\
		realloc.c		\
		show_alloc_mem.c	\
		free.c			\
		my_put_nbr.c		\
		my_putnbr_base.c	\

# Project variables

OBJ	= $(addprefix src/, $(SRC:.c=.o))

INC	= -Iinclude/

RM	= rm -f

ifeq ($(DEBUG), YES)
CFLAGS	= -W -Wall -Wextra -g -D DEBUG -O0 -fpic
else
CFLAGS	= -W -Wall -Wextra -Werror -fpic
endif

LDFLAGS	= -shared

NAME	= libmy_malloc.so

CC	= gcc


#Project Rules

$(NAME):		$(OBJ)
ifeq ($(DEBUG), YES)
			@tput setaf 1; tput bold;
			@echo " ____________________ ________________________   ____ ___._________________";
			@echo "/   _____/\_   _____|/  _____/\_   _____/  _  \ |    |   \    | \__    ___/";
			@echo "\_____  \  |    ___|/   \  ___ |    __)/  / \  \|    |   /    |   |    |";
			@echo "/        \ |        \    \_\  \|     \/    |    \    |  /|    |___|    |";
			@echo "/________//_________/\________/\_____/\____|____/______/ |________|____|";
			@tput sgr0
endif
			@echo -e "\n\n$(RED)Linking with :$(WHITE)\n"
			@echo -e "$(RED)CC$(WHITE)     = $(CC)"
			@echo -e "$(RED)CFLAGS$(WHITE) = $(CFLAGS)"
			@$(CC) $(OBJ) -o $(NAME) $(INC) $(LDFLAGS)
			@echo -e "$(BLUE) \t \t \n \t ♩♪♫ $(NAME) Library® Compiled Sucesfully $(WHITE)\n"

all:
			@make -s $(NAME)

clean:
			@$(RM) $(OBJ)
			@echo -e "[ $(RED)OK$(WHITE) ] clean sucessfull"

fclean: 		clean
			@$(RM) $(NAME)
			@echo -e "[ $(RED)OK$(WHITE) ] fclean succesfull"

re:			fclean all

%.o:                    %.c
			@echo -e "[ $(BLUE)OK$(WHITE) ] Compiling" $<
			@$(CC) -o $@ -c $< $(CFLAGS) $(INC)
