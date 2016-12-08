/*
** get_info.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Thu Apr  7 15:51:39 2016 Jean PLANCHER
** Last update Sun Apr 10 22:59:39 2016 Jean PLANCHER
*/

#include "my.h"

int		get_history(int fd)
{
  static int	fd_history = 0;

  if (fd == -1)
    return (fd_history);
  fd_history = fd;
  return (0);
}

int		get_stdin(int fd)
{
  static int	fd_in = 0;

  if (fd == -1)
    return (fd_in);
  fd_in = fd;
  return (0);
}

int		get_stdout(int fd)
{
  static int	fd_out = 1;

  if (fd == -1)
    return (fd_out);
  fd_out = fd;
  return (1);
}

int		get_stderr(int fd)
{
  static int	fd_err = 2;

  if (fd == -1)
    return (fd_err);
  fd_err = fd;
  return (2);
}

int		get_pipes(int pipe)
{
  static int	nb_pipes = 0;

  nb_pipes += pipe;
  return (nb_pipes);
}
