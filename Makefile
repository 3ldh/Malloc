##
## Makefile for MALLOC in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Wed Jan 25 20:56:18 2017 bougon_p
## Last update Thu Jan 26 17:46:10 2017 Sauvau Mathieu
##

DEBUG	= NO



# Color variables

BLUE	= \033[1;34m

WHITE   = \033[0m

RED	= \033[1;31m



# Sources variables

SRC	= 	malloc.c	\
		malloc_utilities.c \
		realloc.c \
		show_alloc_mem.c \
		free.c \

# Test Variables

SRCTEST	 	=	main.c

NAMETEST 	=	unit_test_malloc

OBJTEST		= 	$(addprefix src/, $(SRCTEST:.c=.o))

TESTLDFLAGS 	= 	-lmy_malloc -L.

# Project variables

OBJ	= $(addprefix src/, $(SRC:.c=.o))

INC	= -Iinclude/

RM	= rm -f

ifeq ($(DEBUG), YES)
CFLAGS	= -W -Wall -Wextra -g -D DEBUG -O0
else
CFLAGS	= -W -Wall -Wextra -Werror
endif

NAME	= libmy_malloc.so

CC	= gcc


#Project Rules

$(NAME):		$(OBJ) $(OBJTEST)
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
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo -e "$(BLUE) \t \t \n \t ♩♪♫ $(NAME) Library® Compiled Sucesfully $(WHITE)\n"
ifeq ($(DEBUG), YES)
			@$(CC) $(OBJTEST) -o $(NAMETEST) $(INC) $(TESTLDFLAGS)
			@echo -e "$(BLUE) \t \t \n \t ♩♪♫ $(NAME) Unit Tests are ready to break your malloc $(WHITE)\n"
else
			@$(RM) $(OBJTEST)
endif

all:
			@make -s $(NAME)

clean:
			@$(RM) $(OBJ) $(OBJTEST)
			@echo -e "[ $(RED)OK$(WHITE) ] clean sucessfull"

fclean: 		clean
			@$(RM) $(NAME) $(NAMETEST)
			@echo -e "[ $(RED)OK$(WHITE) ] fclean succesfull"

re:			fclean all

%.o:                    %.c
			@echo -e "[ $(BLUE)OK$(WHITE) ] Compiling" $<
			@$(CC) -o $@ -c $< $(CFLAGS) $(INC)
