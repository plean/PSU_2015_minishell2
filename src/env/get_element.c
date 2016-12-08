/*
** get_element.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/env/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Apr 12 00:31:38 2016 Jean PLANCHER
** Last update Tue Apr 12 00:31:39 2016 Jean PLANCHER
*/

#include "my.h"

static int	get_ve(const char *str)
{
  int		i;

  i = -1;
  while (str[++i] != '=' && str[i]);
  return (i);
}

t_env	*get_element(const char *env)
{
  t_env	*new_env;
  int	i;
  int	j;

  i = get_ve(env) + 1;
  new_env = my_malloc(sizeof(t_env));
  new_env->env = my_malloc(sizeof(char) * i);
  my_memset(new_env->env, 0, i);
  my_strncpy(new_env->env, env, i - 1);
  if (i != (int)my_strlen(env))
    {
      j = my_strlen(env) - i + 2;
      new_env->data = my_malloc(sizeof(char) * j);
      my_memset(new_env->data, 0, j);
      my_strncpy(new_env->data, &env[i], j - 1);
    }
  else
    new_env->data = NULL;
  return (new_env);
}
