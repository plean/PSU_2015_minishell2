/*
** main.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar 29 12:15:58 2016 Jean PLANCHER
** Last update Tue Apr 12 00:32:19 2016 Jean PLANCHER
*/

#include "my.h"

int			execute_shell(t_list *list,
				      char *buffer)
{
  char ATC_TAB		**tab;

  tab = NULL;
  test_exit(buffer, list);
  if (!buffer[0] || my_ambiguous(buffer) || null_command(buffer) ||
      (get_fd(buffer)))
    return (1);
  cut_space(buffer);
  if (!buffer[0])
    {
      write(2, "Invalid null command.\n", 22);
      return (1);
    }
  check_nb_pipes(buffer);
  tab = my_str_to_tab(buffer, '|', '|');
  do_fork(list, tab, 0);
  return (0);
}

static int		pars_commands(t_list *list)
{
  char ATC_TAB		**tab;
  char ATC_STR		*buffer;
  int			i;
  int			e;

  buffer = get_next_line(0);
  cut_space(buffer);
  write(get_history(-1), buffer, my_strlen(buffer));
  if (buffer)
    write(get_history(-1), "\n", 1);
  test_exit(buffer, list);
  tab = my_str_to_tab(buffer, ';', ';');
  i = -1;
  e = get_pv(buffer);
  while (++i < e)
    {
      if (!tab[i] || !tab[i][0])
	continue;
      reset_fd();
      tab[i] = cut_space(tab[i]);
      execute_shell(list, tab[i]);
    }
  return (1);
}

int		main(int ac, char *const *av, char *const *envp)
{
  t_list	*list;
  int		fd;
  int		i;

  if (ac > 1 && test_flags(av))
    return (0);
  if (signal(SIGINT, SIG_IGN) == SIG_ERR ||
      signal(SIGTSTP, SIG_IGN) == SIG_ERR)
    my_exit(84);
  list = create_list();
  i = -1;
  while (envp[++i])
    add_element_e(&list, get_element(envp[i]));
  if ((fd = open(MYSH_HISTORY, O_CREAT | O_WRONLY | O_APPEND, 00644)) == -1 ||
      get_history(fd))
    {
      write(2, "Failed to open history.\n", 24);
      get_history(0);
    }
  load_rc(list);
  while (aff_promt(list) && pars_commands(list));
  return (0);
}
