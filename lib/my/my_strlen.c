/*
** my_strlen.c for my_string in /home/melis_m/code/libmy/src/my_string/
**
** Made by Matteo Melis
** Login   <melis_m@epitech.eu>
**
** Started on  Wed Mar 23 01:55:22 2016 Matteo Melis
** Last update Tue Mar 29 16:20:19 2016 Jean PLANCHER
*/

#include "my.h"

size_t			my_strlen(const char *s)
{
  register const char	*str;

  if (s == NULL)
    return (0);
  str = s;
  while (*++str);
  return (str - s);
}
