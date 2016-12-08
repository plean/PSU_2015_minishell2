/*
** do_fork.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat Apr  9 19:14:23 2016 Jean PLANCHER
** Last update Mon Apr 11 18:19:50 2016 Jean PLANCHER
*/

#include "my.h"

static void	test_sigsegv(int status)
{
  if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == SIGSEGV)
	write(get_stderr(-1), "Segmentation fault\n", 19);
    }
}

static void	write_and_exit(const char *str)
{
  write(2, str, my_strlen(str));
  my_exit(42);
}

static void	do_son(t_list *list, char **tab, int fd[2], int i)
{
  char		**cmd;

  if ((dup2(get_stdin(-1), 0) == -1) ||
      (dup2((get_pipes(0) == i) ? get_stdout(-1) : fd[1], 1) == -1) ||
      (dup2(get_stderr(-1), 2) == -1))
    write_and_exit("Dup2 failed.\n");
  if (get_pipes(0) != i)
    {
      close(fd[1]);
      close(fd[0]);
    }
  tab[i] = cut_space(tab[i]);
  test_exit(tab[i], list);
  cmd = my_str_to_tab(tab[i], ' ', '\t');
  if (get_pipes(0) == i || !test_builtins(list, cmd))
    my_commands(list, cmd);
  my_exit(1);
}

void	do_fork(t_list *list, char **tab, int i)
{
  pid_t		pid;
  int		status;
  int		fd[2];

  tab[i] = cut_space(tab[i]);
  if (get_pipes(0) == i &&
      test_builtins(list, my_str_to_tab(tab[i], ' ', '\t')))
    return ;
  if ((get_pipes(0) != i && pipe(fd) == -1) || ((pid = fork()) == -1))
    write_and_exit((pid == -1) ? "Error : Fork failed\n" : "Pipe failed.\n");
  if (pid > 0)
    {
      if (get_pipes(0) != i)
	{
	  get_stdin(fd[0]);
	  close(fd[1]);
	  do_fork(list, tab, ++i);
	  close(fd[0]);
	}
      waitpid(pid, &status, 0);
    }
  else if (pid == 0)
    do_son(list, tab, fd, i);
  test_sigsegv(status);
}
