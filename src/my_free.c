/*
** my_free.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar 29 17:23:17 2016 Jean PLANCHER
** Last update Fri Apr  8 08:57:00 2016 Jean PLANCHER
*/

#include "my.h"

void	free_str(char **to_free)
{
  if (*to_free == NULL)
    return ;
  free(*to_free);
}

void	free_tab(char ***to_free)
{
  int	i;

  i = -1;
  if (*to_free == NULL)
    return ;
  while ((*to_free)[++i] && (*to_free)[i][0])
    free((*to_free)[i]);
  free(*to_free);
}
