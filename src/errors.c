/*
** errors.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Apr  5 18:01:26 2016 Jean PLANCHER
** Last update Mon Apr 11 18:26:19 2016 Jean PLANCHER
*/

#include "my.h"

int	null_command(const char *buffer)
{
  int	i;
  int	e;
  int	k;

  e = k = 0;
  i = -1;
  if (buffer[0] == '|')
    return (write(2, "Invalid null command.\n", 22));
  while (buffer[++i])
    {
      if (buffer[i] == ' ' || buffer[i] == '\t')
	continue;
      e = (buffer[i] == '|') ? e + 1 : 0;
      if (e == 2)
	return (write(2, "Invalid null command.\n", 22));
      if (buffer[i] == '>')
	k = 1;
      if (e && k)
	return (write(2, "Ambiguous output redirect.\n", 27));
    }
  if (e)
    return (write(2, "Invalid null command.\n", 22));
  return (0);
}

int	my_ambiguous(const char *buffer)
{
  int		i[2];
  int		k[4];
  int		e[2];

  i[0] = i[1] = e[0] = e[1] = 0;
  my_memset(k, 0, sizeof(int) * 4);
  while (buffer[i[0]])
    {
      (buffer[i[0]] == '|') ? i[1] = 1 : 0;
      if ((!my_strncmp(&buffer[i[0]], "<<", 1) && (++k[0]) && (++e[0])) ||
	  (!my_strncmp(&buffer[i[0]], ">>", 1) && (++k[1]) && (++e[1])))
	i[0] += 2;
      else if ((buffer[i[0]] == '>' && (++k[3]) && (++e[1])) ||
	       (buffer[i[0]] == '<' && (++k[2]) && (++e[0])) || !(e[0] = e[1] = 0))
	i[0]++;
      if (e[0] + e[1] == 2)
	return (write(2, "Missing name for redirect.\n", 27));
      if (e[0] && i[1])
	return (write(2, "Ambiguous input redirect.\n", 26));
    }
  if (k[0] > 1 || k[2] > 1 || k[0] * k[2])
    return (write(2, "Ambiguous input redirect.\n", 26));
  else if (k[1] > 1 || k[3] > 1 || k[1] * k[3])
    return (write(2, "Ambiguous output redirect.\n", 27));
  return (0);
}

int	relat_path(const char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == '/')
	return (1);
    }
  return (0);
}

int	is_a_dir(const char *str)
{
  int   fd;

  fd = open(str, O_DIRECTORY);
  if (fd != -1)
    close(fd);
  return (fd != -1);
}

int	test_flags(char *const *argv)
{
  if (!my_strcmp(argv[1], "-h") ||
      !my_strcmp(argv[1], "--help"))
    {
      aff_help(argv[0]);
      return (1);
    }
  else if (!my_strcmp(argv[1], "-v") ||
	   !my_strcmp(argv[1], "--version"))
    {
      aff_help(argv[0]);
      return (1);
    }
  return (0);
}
