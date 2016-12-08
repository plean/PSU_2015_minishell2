##
## Makefile for  in /home/planch_j/rendu/CPE/CPE_2015_corewar/corewar/parsing/src/
##
## Made by Jean PLANCHER
## Login   <planch_j@epitech.net>
##
## Started on  Wed Mar 23 15:06:06 2016 Jean PLANCHER
## Last update Wed Apr 20 21:42:31 2016 Jean PLANCHER
##

CC	=	gcc

CFLAGS  += -W -Wall -Wextra -lmy
CFLAGS	+= -I../include/ -L../lib/

RM	=	rm -f

NAME	=	../mysh

SRCS	= main.c \
	  promt.c \
		cut_space.c \
		get_next_line.c \
		builtins.c \
		my_free.c \
		commands.c \
		do_fork.c \
		misc.c \
		get_fd.c \
		get_info.c \
		move_dir.c \
		load_rc.c \
		swap_str.c \
		errors.c \
		flags.c \
		env/env.c \
		env/get_element.c \
		alias/alias.c \
		alias/init_alias.c \
		list/list.c \
		list/find_env.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		@echo -e "\e[0m"
		@$(CC) $(OBJS) -o $(NAME) $(CFLAGS)
		@echo -e "\e[32mAll done ! ==>\e[33m" $(NAME) "\e[32mcreated !\e[0m"

clean:
		@echo -en "\e[0mCleaning .o files..."
		@$(RM) $(OBJS)
		@echo -e "	 [\e[32mOk !\e[39m]\e[0m"

fclean:		clean
		@echo -en "\e[39mCleaning executable..."
		@$(RM) $(NAME)
		@echo -e "		 [\e[32m0k !\e[39m]\e[0m"

re:		fclean all

.c.o:%.c
	@$(CC) -c $< -o $@ $(CFLAGS) && \
	echo -e "\e[32m[OK]" $< "\e[93m"|| \
	echo -e "\e[91;5m[ERR]\e[25m" $< "\e[93m"

.PHONY:		all clean fclean re
