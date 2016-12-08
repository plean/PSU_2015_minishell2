/*
** my_malloc.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/lib/my/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Apr  1 16:27:44 2016 Jean PLANCHER
** Last update Fri Apr  1 16:30:20 2016 Jean PLANCHER
*/

#include "my.h"

void	*my_malloc(size_t nb)
{
  void	*tmp;

  if ((tmp = malloc(nb)) == NULL)
    {
      write(2, "Error: Malloc Failed\n", 21);
      my_exit(42);
    }
  return (tmp);
}
