/*
** alias.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/alias/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Apr 12 00:07:21 2016 Jean PLANCHER
** Last update Tue Apr 12 00:54:03 2016 Jean PLANCHER
*/

#include "my.h"

void		add_alias(const char **tab)
{
  t_list	*list;
  t_env		*temp;

  list = get_alias(NULL);
  temp = my_malloc(sizeof(t_env));
  temp->env = my_malloc(sizeof(char) * (my_strlen(tab[0]) + 1));
  my_strcpy(temp->env, tab[0]);
  temp->data = my_malloc(sizeof(char) * (my_strlen(tab[1]) + 1));
  my_strcpy(temp->data, tab[1]);
  add_element_e(&list, temp);
}

void		aff_alias(const char *str)
{
  t_element	*tmp;
  t_env		*env;

  if (str == NULL)
    return (print_list(get_alias(NULL), ' '));
  if ((tmp = find_env(get_alias(NULL), str)) == NULL)
    return ;
  env = (t_env *)tmp->data;
  write(get_stdout(-1), env->env, my_strlen(env->env));
  write(get_stdout(-1), " ", 1);
  write(get_stdout(-1), env->data, my_strlen(env->data));
  write(get_stdout(-1), "\n", 1);
}
