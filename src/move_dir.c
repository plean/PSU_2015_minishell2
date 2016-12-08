/*
** move_dir.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Apr  3 19:43:50 2016 Jean PLANCHER
** Last update Thu Apr  7 00:15:39 2016 Jean PLANCHER
*/

#include "my.h"

int	check_dir(char *str)
{
  if (my_access(str, F_OK) == -1)
    {
      write(2, "Error: No such file or directory.\n", 34);
      return (0);
    }
  else if (my_access(str, R_OK) == -1)
    {
      write(2, "Error: Permission denied.\n", 26);
      return (0);
    }
  return (1);
}

static int	move_directory(t_list *list, char *str)
{
  t_element	*pwd;
  t_element	*oldpwd;
  char		tmp[PATH_MAX];

  oldpwd = find_env(list, "OLDPWD");
  pwd = find_env(list, "PWD");
  swap_str(&((t_env *)oldpwd->data)->data, ((t_env *)pwd->data)->data);
  if (check_dir(str))
    {
      if (chdir(str))
	return (write(2, "cd: Can't change to working directory.\n", 39));
    }
  if (!(getcwd(tmp, PATH_MAX)))
    {
      write(2, "cd: Can't find working directory\n", 33);
      return (1);
    }
  swap_str(&((t_env *)(pwd->data))->data, tmp);
  return (0);
}

static int	move_oldpwd(t_list *list)
{
  t_element	*pwd;
  t_element	*oldpwd;
  char		*tmp;

  tmp = NULL;
  oldpwd = find_env(list, "OLDPWD");
  pwd = find_env(list, "PWD");
  if (!((t_env *)oldpwd->data)->data ||
      chdir(((t_env *)oldpwd->data)->data))
    return (write(2, "cd: Can't change to old working directory.\n", 43));
  swap_str(&tmp, ((t_env *)oldpwd->data)->data);
  swap_str(&((t_env *)(oldpwd->data))->data, ((t_env *)pwd->data)->data);
  if (tmp)
    swap_str(&((t_env *)(pwd->data))->data, tmp);
  return (0);
}

static int	move_home(t_list *list)
{
  t_element	*home;
  t_element	*pwd;
  t_element	*oldpwd;

  home = find_env(list, "HOME");
  if (!home)
    return (write(2, "cd: No home directory.\n", 23));
  oldpwd = find_env(list, "OLDPWD");
  pwd = find_env(list, "PWD");
  if (!((t_env *)home->data)->data ||
      chdir(((t_env *)home->data)->data))
    return (write(2, "cd: Can't change to home directory.\n", 39));
  swap_str(&((t_env *)(oldpwd->data))->data, ((t_env *)pwd->data)->data);
  swap_str(&((t_env *)(pwd->data))->data, ((t_env *)home->data)->data);
  return (0);
}

void		move_dir(t_list *list, char **tab)
{
  char		str[PATH_MAX];
  char		**pwd;

  if (!find_env(list, "PWD"))
    {
      pwd = my_malloc(sizeof(char *) * 4);
      if (!(getcwd(str, PATH_MAX)))
	{
	  write(2, "cd: Can't find working directory\n", 33);
	  return ;
	}
      pwd[0] = "setenv";
      pwd[1] = "PWD";
      pwd[2] = str;
      pwd[3] = NULL;
      new_env(list, pwd);
    }
  if (!find_env(list, "OLDPWD"))
    new_env(list, my_str_to_tab("setenv OLDPWD", ' ', ' '));
  if (!tab[1])
    move_home(list);
  else if (!my_strcmp(tab[1], "-"))
    move_oldpwd(list);
  else
    move_directory(list, tab[1]);
}
