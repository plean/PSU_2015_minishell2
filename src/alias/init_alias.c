/*
** init_alias.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/alias/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Apr 12 00:13:03 2016 Jean PLANCHER
** Last update Tue Apr 12 00:13:04 2016 Jean PLANCHER
*/

#include "my.h"

t_list			*get_alias(t_element *new_elem)
{
  static t_list		*alias = NULL;

  if (!alias)
    alias = create_list();
  if (new_elem == NULL)
    return (alias);
  add_element_e(&alias, new_elem);
  return (NULL);
}
