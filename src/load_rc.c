/*
** load_rc.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Mon Apr 11 19:29:44 2016 Jean PLANCHER
** Last update Mon Apr 11 22:51:22 2016 Jean PLANCHER
*/

#include "my.h"

static int	penis(t_list *list, int fd)
{
  char ATC_TAB		**tab = NULL;
  char ATC_STR		*buffer = NULL;
  int			i[2];

  if ((buffer = get_next_line(fd)) == NULL)
    return (1);
  if (!buffer[0] || buffer[0] == '#')
    return (0);
  cut_space(buffer);
  test_exit(buffer, list);
  tab = my_str_to_tab(buffer, ';', ';');
  i[0] = -1;
  i[1] = get_pv(buffer);
  while (++i[0] < i[1])
    {
      if (!tab[i[0]] || !tab[i[0]][0])
	continue;
      reset_fd();
      tab[i[0]] = cut_space(tab[i[0]]);
      execute_shell(list, tab[i[0]]);
    }
  return (0);
}

void			load_rc(t_list *list)
{
  int			fd;

  if ((fd = open(MYSH_RC, O_RDONLY)) == -1)
    return ;
  while (!penis(list, fd));
  close(fd);
}
