/*
** swap_str.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Apr  3 20:43:34 2016 Jean PLANCHER
** Last update Sun Apr  3 21:06:31 2016 Jean PLANCHER
*/

#include "my.h"

void	swap_str(char **str1, const char *str2)
{
  int	i;

  i = my_strlen(str2) + 1;
  if (*str1)
    free(*str1);
  *str1 = my_malloc(sizeof(char) * i);
  my_memset(*str1, 0, i);
  my_strcpy(*str1, str2);
}
