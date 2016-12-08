/*
** env.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/env/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Thu Mar 31 17:37:47 2016 Jean PLANCHER
** Last update Tue Apr 12 00:33:36 2016 Jean PLANCHER
*/

#include "my.h"

void		print_list(t_list *list, char c)
{
  t_element	*tmp;
  t_env		*data;

  tmp = list->first;
  while (tmp)
    {
      data = (t_env *)tmp->data;
      if (data->env)
	write(get_stdout(-1), data->env, my_strlen(data->env));
      write(get_stdout(-1), &c, 1);
      if (data->data)
	write(get_stdout(-1), data->data, my_strlen(data->data));
      write(get_stdout(-1), "\n", 1);
      tmp = tmp->next;
    }
}

void	new_env(t_list *list, char **tab)
{
  t_env	*env;

  env = my_malloc(sizeof(t_env));
  env->env = my_malloc(sizeof(char) * (my_strlen(tab[1]) + 1));
  my_strcpy(env->env, tab[1]);
  env->data = NULL;
  if (tab[2])
    {
      env->data = my_malloc(sizeof(char) * (my_strlen(tab[2]) + 1));
      my_strcpy(env->data, tab[2]);
    }
  add_element_e(&list, env);
}

void		set_env(t_list *list, char **tab)
{
  t_element	*tmp;
  t_env		*env;

  tmp = list->first;
  while (tmp)
    {
      env = (t_env *)tmp->data;
      if (!my_strcmp(env->env, tab[1]))
	{
	  free(env->data);
	  env->data = NULL;
	  if (tab[2])
	    {
	      env->data = my_malloc(sizeof(char) * (my_strlen(tab[2]) + 1));
	      my_strcpy(env->data, tab[2]);
	    }
	  break ;
	}
      tmp = tmp->next;
    }
  if (!tmp)
    new_env(list, tab);
}

void		unset_env(t_list *list, char **tab)
{
  t_element	*tmp;
  t_env		*env;
  int		i;

  i = 0;
  while (tab[++i])
    {
      tmp = list->first;
      while (tmp)
	{
	  env = (t_env *)tmp->data;
	  if (!my_strcmp(env->env, tab[i]))
	    {
	      del_elem(&list, tmp);
	      break ;
	    }
	  tmp = tmp->next;
	}
    }
}
