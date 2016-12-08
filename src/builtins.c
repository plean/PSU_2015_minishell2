/*
** builtins.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar 29 16:35:10 2016 Jean PLANCHER
** Last update Tue Apr 12 22:28:06 2016 Jean PLANCHER
*/

#include "my.h"

static int	test_newenv(const char *str)
{
  int		i;

  i = -1;
  if (!((str[0] <= 'z' && str[0] >= 'a') || (str[0] <= 'Z' && str[0] >= 'A') ||
	(str[0] == '_')))
    return (write(get_stderr(-1),
		  "setenv: Variable name must begin with a letter.\n", 48));
    while (str[++i])
	{
	  if (!((str[i] <= 'z' && str[i] >= 'a') ||
		(str[i] <= 'Z' && str[i] >= 'A') ||
		(str[i] == '_')))
	    return (write(get_stderr(-1),
			  "setenv: Variable name must contain alphanumeric characters.\n",
			  60));
	}
  return (0);
}

void	test_exit(char *buffer, t_list *list)
{
  if (buffer == NULL || !my_strcmp(buffer, "exit") ||
      (!my_strncmp(buffer, "exit ", 4) && is_alpha(&buffer[5], '-')))
    {
      write(get_stdout(-1), "exit\n", 5);
      del_list(&list);
      my_exit((buffer && buffer[4]) ?
	      my_getnbr_base(&buffer[5], "0123456789") : 0);
    }
}

int	test_builtins(t_list *list, char **tab)
{
  if (!my_strcmp(tab[0], "cd"))
    (!tab[1] || !tab[2]) ? move_dir(list, tab) :
  write(get_stderr(-1), "cd: Too many arguments.\n", 24);
  else if (!my_strcmp(tab[0], "alias"))
    (tab[1] && tab[2]) ? add_alias((const char **)&tab[1]) : aff_alias(tab[1]);
  else if (!my_strcmp(tab[0], "env"))
    print_list(list, '=');
  else if (!my_strcmp(tab[0], "setenv"))
    (tab[1]) ? ((tab[2] && tab[3]) ? write(get_stderr(-1),
		"setenv: Too many arguments.\n", 28) : ((!test_newenv(tab[1]))
		? set_env(list, tab) : 0)) : print_list(list, '=');
  else if (!my_strcmp(tab[0], "unsetenv"))
    (tab[1]) ? unset_env(list, tab) :
  write(get_stderr(-1), "unsetenv: Too few arguments.\n", 29);
  else
    return (0);
  return (1);
}
