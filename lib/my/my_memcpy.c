/*
** my_memcpy.c for my_string.h in /home/melis_m/code/rendu/CPE_2015_corewar/corewar/functions/lib/my/my_string/
**
** Made by Matteo Melis
** Login   <melis_m@epitech.eu>
**
** Started on  Thu Mar 24 22:55:47 2016 Matteo Melis
** Last update Tue Mar 29 14:00:36 2016 Jean PLANCHER
*/

#include "my.h"

void		*my_memcpy(void *dest, const void *src, size_t n)
{
  size_t	i;
  char		*s1;
  char		*s2;

  i = 0;
  s1 = (char *)dest;
  s2 = (char *)src;
  while (i < n)
    {
      s1[i] = s2[i];
      i += 1;
    }
  return (s1);;
}
