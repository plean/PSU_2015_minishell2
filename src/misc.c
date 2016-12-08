/*
** misc.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat Apr  9 11:20:27 2016 Jean PLANCHER
** Last update Mon Apr 11 17:36:53 2016 Jean PLANCHER
*/

#include "my.h"

void	replace_next_word(char *str)
{
  int	i;

  i = -1;
  while (str[++i] && str[i] == ' ');
  i--;
  while (str[++i] && str[i] != ' ')
    str[i] = ' ';
  i--;
  while (str[++i] && str[i] == ' ');
  i--;
  while (str[++i] && str[i] != ' ')
    str[i] = ' ';
}

void	check_nb_pipes(const char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == '|')
	get_pipes(1);
    }
}

void	reset_fd(void)
{
  get_stdin(0);
  get_stdout(1);
  get_stderr(2);
  if (get_pipes(0))
    while (get_pipes(-1));
}

int	get_pv(char *str)
{
  int	i;
  int	e;

  if (!str)
    return (0);
  i = -1;
  e = 1;
  while (str[++i])
    e += (str[i] == ';') ? 1 : 0;
  return (e);
}
