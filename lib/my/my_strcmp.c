/*
** my_strcmp.h for my_string in /home/melis_m/code/libmy/src/my_string/
**
** Made by Matteo Melis
** Login   <melis_m@epitech.eu>
**
** Started on  Wed Mar 23 02:58:30 2016 Matteo Melis
** Last update Tue Mar 29 14:00:33 2016 Jean PLANCHER
*/

#include "my.h"

int		my_strcmp(const char *s1, const char *s2)
{
  const char	*s3;
  const char	*s4;

  s3 = s1;
  s4 = s2;
  while (*s3 == *s4)
    {
      s3++;
      s4++;
      if (!*s3)
	return (*s3 - *s4);
    }
  return (*s3 - *s4);
}

int			my_strncmp(const char *s1, const char *s2, size_t n)
{
  register const char	*s3;
  register const char	*s4;

  s3 = s1;
  s4 = s2;
  while (*s3 == *s4 && (unsigned)(s4 - s2) < n)
    {
      s3++;
      s4++;
      if (!*s3)
	return (*s3 - *s4);
    }
  return (*s3 - *s4);
}
