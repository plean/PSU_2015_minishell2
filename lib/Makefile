##
## Makefile for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/lib/
##
## Made by Jean PLANCHER
## Login   <planch_j@epitech.net>
##
## Started on  Tue Mar 29 14:09:22 2016 Jean PLANCHER
## Last update Wed Apr 20 21:42:43 2016 Jean PLANCHER
##

CP      = cp

CC      = cc -I./include

AR      = ar rc

RAN     = ranlib

NAME    = libmy.a

RM      = rm -f

FOLDER	= my/

SRCS    = $(addprefix $(FOLDER), \
	  my_putnbr_base.c \
	  my_getnbr_base.c \
		is_alpha.c \
		my_exit.c \
		my_lseek.c \
		my_execve.c \
		my_malloc.c \
		my_access.c \
		my_memcpy.c \
		my_memset.c \
		my_strcmp.c \
		my_strcpy.c \
		my_str_to_tab.c \
		my_strlen.c)

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wall -Wextra -O3 -I../include

all: $(NAME)

$(NAME):	$(OBJS)
		@echo -e "\e[0m"
		$(AR) $(NAME) $(OBJS)
		ranlib $(NAME)
		@echo -e "\e[32mAll done ! ==>\e[33m" $(NAME) "\e[32mcreated !\e[0m"

clean:
		@echo -en "\e[0mCleaning .o files..."
		@$(RM) $(OBJS)
		@echo -e "	 [\e[32mOk !\e[39m]\e[0m"

fclean:	clean
		@echo -en "\e[39mCleaning executable..."
		@$(RM) $(NAME)
		@echo -e "		 [\e[32m0k !\e[39m]\e[0m"

re:	fclean all

.PHONY:		all clean fclean re

.c.o:%.c
	@$(CC) -c $< -o $@ $(CFLAGS) && \
	echo -e "\e[32m[OK]" $< "\e[93m"|| \
	echo -e "\e[91;5m[ERR]\e[25m" $< "\e[93m"
