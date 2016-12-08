/*
** my_exit.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar 29 12:56:23 2016 Jean PLANCHER
** Last update Wed Apr  6 22:36:49 2016 Jean PLANCHER
*/

#include "my.h"

void			my_exit(int nb)
{
  __asm__ __volatile__	("syscall"
			 :
			 : "a" (60), "D" (nb)
			 : "rcx", "r11", "cc");
}
