##
## Makefile for  in /home/planch_j/rendu/github/PSU/PSU_2015_minishell2
## 
## Made by Jean PLANCHER
## Login   <planch_j@epitech.net>
## 
## Started on  Fri Apr 22 21:23:23 2016 Jean PLANCHER
## Last update Fri Apr 22 21:23:24 2016 Jean PLANCHER
##

all:
	make -C lib
	make -C src

clean:
	make clean -C lib
	make clean -C src

fclean: clean
	make fclean -C lib
	make fclean -C src

re: fclean all

.PHONY: all clean fclean re
