/*
** promt.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar 29 15:54:34 2016 Jean PLANCHER
** Last update Tue Apr 12 22:58:44 2016 Jean PLANCHER
*/

#include "my.h"

int		aff_promt(t_list *list)
{
  t_element	*tmp;
  t_env		*env;
  char		*str;
  int		i;
  int		k;

  tmp = find_env(list, "PWD");
  if (tmp && ((t_env *)tmp->data)->data)
    {
      env = (t_env *)tmp->data;
      k = my_strlen(env->data);
      i = -1;
      while ((++i + 1) && --k && env->data[k] != '/');
      if (k)
	{
	  while (--k && env->data[k] != '/')
	    i++;
	}
      str = my_malloc(sizeof(char) * (i + 2));
      my_strcpy(str, &env->data[k + (env->data[k] == '/')]);
      write(1, str, i + 1);
    }
  write(1, "> ", 2);
  return (1);
}
