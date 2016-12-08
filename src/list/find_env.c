/*
** find_env.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/list/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Apr  3 19:57:20 2016 Jean PLANCHER
** Last update Tue Apr 12 00:52:11 2016 Jean PLANCHER
*/

#include "my.h"

t_element	*find_env(t_list *list, const char *str)
{
  t_element	*tmp;
  t_env		*env;

  tmp = list->first;
  while (tmp)
    {
      env = (t_env *)tmp->data;
      if (!my_strcmp(env->env, str))
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
