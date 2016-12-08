/*
** cut_space.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar 29 15:56:43 2016 Jean PLANCHER
** Last update Sat Apr  9 13:44:46 2016 Jean PLANCHER
*/

#include "my.h"

char	*cut_space(char *buffer)
{
  int	i;
  int	e;

  e = 0;
  i = -1;
  if (!buffer)
    return (NULL);
  while (buffer[++i])
    {
      if (buffer[i] != ' ' && buffer[i] != '\t')
	buffer[e++] = buffer[i];
      if ((buffer[i] == ' ' || buffer[i] == '\t') && e > 0 &&
	  buffer[e - 1] != ' ' && buffer[e - 1] != '\t')
	buffer[e++] = ' ';
    }
  if (e && buffer[e - 1] == ' ')
    e--;
  buffer[e] = 0;
  return (buffer);
}
