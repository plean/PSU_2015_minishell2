/*
** get_fd.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Apr  8 15:36:16 2016 Jean PLANCHER
** Last update Sun Apr 10 22:45:27 2016 Jean PLANCHER
*/

#include "my.h"

static int	nextspace(const char *str)
{
  int		i;

  i = -1;
  while (str[++i] && str[i] != ' ');
  return (i);
}

static char	*getnextword(const char *str, char c)
{
  char		*buffer;
  int		i;
  int		k;

  i = -1;
  while (str[++i] == c);
  i--;
  while (str[++i] == ' ');
  k = nextspace(&str[i]);
  buffer = my_malloc(sizeof(char) * (k + 1));
  my_strncpy(buffer, &str[i], k);
  buffer[k] = 0;
  return (buffer);
}

static int	redir_right(const char *str, int e)
{
  char ATC_STR	*buffer;
  int		fd;

  buffer = getnextword(str, '>');
  if (str[1] == '>')
    fd = open(buffer, O_CREAT | O_WRONLY | O_APPEND, 00644);
  else
    fd = open(buffer, O_CREAT | O_WRONLY | O_TRUNC, 00644);
  if (fd == -1)
    {
      write(2, "Open failed.\n", 13);
      return (1);
    }
  (e) ? get_stderr(fd) :  get_stdout(fd);
  return (0);
}

static int	redir_left(const char *str)
{
  char ATC_STR	*buffer;
  char		*tmp;
  int		fd_in;

  buffer = getnextword(str, '<');
  if (str[1] == '<' && (fd_in = open(TMP_FILE, O_TRUNC | O_CREAT | O_RDWR, 00644)))
    while (write(1, "? ", 2) && my_strcmp((tmp = get_next_line(0)), buffer))
	{
	  (tmp) ? write(fd_in, tmp, my_strlen(tmp)) : 0;
	  write(fd_in, "\n", 1);
	  free(tmp);
	}
  else if (str[1] != '<')
    fd_in = open(buffer, O_RDONLY);
  if (fd_in >= 0)
    get_stdin(fd_in);
  else
    {
      write(2, buffer, my_strlen(buffer));
      return (write(2, ": No such file or directory.\n", 29));
    }
  my_lseek(fd_in, 0, 0);
  return (0);
}

int		get_fd(char *str)
{
  int		i;
  int		e;

  i = -1;
  while (str[++i])
    {
      if (str[i] == '>')
	{
	  e = i;
	  if (redir_right(&str[i], (i && str[i - 1] == '2')))
	    return (1);
	  i += (str[i + 1] == '>') ? 1 : 0;
	  (i && str[i - 1] == '2') ? str[i - 1] = ' ' : 0;
	  replace_next_word(&str[e]);
	}
      else if (str[i] == '<')
	{
	  e = i;
	  if (redir_left(&str[i]))
	    return (1);
	  i += (str[i + 1] == '<') ? 1 : 0;
	  replace_next_word(&str[e]);
	}
    }
  return (0);
}
