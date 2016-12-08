/*
** my_access.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/lib/my/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Apr  1 00:30:34 2016 Jean PLANCHER
** Last update Wed Apr  6 22:36:55 2016 Jean PLANCHER
*/

#include "my.h"

int	my_access(const char *pathname, int mode)
{
  int			ret;

  __asm__ __volatile__ ("syscall"
			: "=a" (ret)
			: "a" (21), "D" (pathname), "S" (mode)
			: "rcx", "r11", "cc");
  return (ret);
}
