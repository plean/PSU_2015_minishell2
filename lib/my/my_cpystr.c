/*
** my_cpystr.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/lib/my/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Mon Apr 11 18:11:14 2016 Jean PLANCHER
** Last update Mon Apr 11 18:11:17 2016 Jean PLANCHER
*/

#include "my.h"

char	*my_cpy_str(char *str1, char *str2)
{
  char	*new_str;
  int	i;

  i = my_strlen(str1);
  new_str = my_malloc(sizeof(char) * (my_strlen(str2) + i + 1));
  my_strcpy(new_str, str1);
  my_strcpy(&new_str[i], str2);
  return (new_str);
}
