/*
** my_strcpy.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/lib/my/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar 29 14:01:23 2016 Jean PLANCHER
** Last update Tue Mar 29 14:01:25 2016 Jean PLANCHER
*/

#include "my.h"

char	*my_strcpy(char *dest, const char *src)
{
  char	*s;

  s = dest;
  while ((*s++ = *src++));
  return (dest);
}

char	*my_strncpy(char *dest, const char *src, size_t n)
{
  char	*s;

  s = dest;
  while ((*s++ = *src++) && (unsigned)(s - dest) < n);
  *s = 0;
  return (dest);
}
