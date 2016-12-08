/*
** commands.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Thu Mar 31 18:27:17 2016 Jean PLANCHER
** Last update Tue Apr 12 01:38:33 2016 Jean PLANCHER
*/

#include "my.h"

static char	**list_to_tab(t_list *list)
{
  char		**tab;
  t_element	*tmp;
  t_env		*env;
  int		len;
  int		i;

  i = -1;
  tmp = list->first;
  tab = my_malloc(sizeof(char *) * (list->length + 1));
  my_memset(tab, 0, sizeof(char *) * (list->length + 1));
  while (tmp)
    {
      env = (t_env *)tmp->data;
      len = my_strlen(env->env) + 1;
      tab[++i] = my_malloc(sizeof(char) *
			   (my_strlen(env->data) + len + 1));
      my_strcpy(tab[i], env->env);
      tab[i][len - 1] = '=';
      if (env->data)
	my_strcpy(&tab[i][len], env->data);
      else
	tab[i][len] = 0;
      tmp = tmp->next;
    }
  return (tab);
}

static char	*check_path(char *name, char **path)
{
  char		*p_name;
  int		len;
  int		i;

  i = -1;
  if (!path)
    return (NULL);
  while (path[++i])
    {
      len = my_strlen(path[i]) + 1;
      p_name = my_malloc(sizeof(char) * (my_strlen(name) + len + 1));
      my_strcpy(p_name, path[i]);
      p_name[len - 1] = '/';
      my_strcpy(&p_name[len], name);
      if (!my_access(p_name, F_OK))
	return (p_name);
      free(p_name);
    }
  return (NULL);
}

static char	**get_path(t_list *list)
{
  t_element	*tmp;
  t_env		*env;
  char		**path;

  tmp = list->first;
  path = NULL;
  while (tmp)
    {
      env = (t_env *)tmp->data;
      if (!my_strcmp("PATH", env->env))
	{
	  if (!env->data)
	    return (NULL);
	  path = my_str_to_tab(env->data, ':', ':');
	  break ;
	}
      tmp = tmp->next;
    }
  if (!path)
    path = my_str_to_tab(PATH_ENV, ':', ':');
  return (path);
}

void		my_commands(t_list *list, char **tab)
{
  char ATC_TAB	**path;
  char ATC_TAB	**envp;
  char ATC_STR	*name;
  int		k;

  k = !relat_path(tab[0]);
  path = get_path(list);
  name = (list->first) ? check_path(tab[0], path) : NULL;
  envp = list_to_tab(list);
  if (is_a_dir(tab[0]))
    {
      write(get_stderr(-1), tab[0], my_strlen(tab[0]));
      write(get_stderr(-1), ": Is a directory.\n", 18);
    }
  else if (name && k && !my_access(name, F_OK))
    my_execve(name, tab, envp);
  else if ((!k || !path) && !my_access(tab[0], F_OK))
    my_execve(tab[0], tab, envp);
  else
    {
      write(get_stderr(-1), tab[0], my_strlen(tab[0]));
      write(get_stderr(-1), ": Command not found.\n", 21);
    }
}
