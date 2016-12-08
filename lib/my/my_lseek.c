/*
** my_lseek.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/lib/my/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Apr 10 22:09:15 2016 Jean PLANCHER
** Last update Sun Apr 10 22:13:17 2016 Jean PLANCHER
*/

#include "my.h"

off_t	my_lseek(int fd, off_t offset, int whence)
{
  off_t	ret;

  __asm__ __volatile__ ("syscall"
			 : "=a" (ret)
			 : "a" (8), "D" (fd), "S" (offset), "d" (whence)
			 : "rcx", "r11", "cc");
  return (ret);
}
