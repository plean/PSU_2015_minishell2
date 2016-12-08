/*
** get_next_line.c for  in /home/planch_j/rendu/CPE/CPE_2015_getnextline
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Mon Jan  4 18:19:56 2016 Jean PLANCHER
** Last update Mon Apr 11 22:42:55 2016 Jean PLANCHER
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

static int	my_lenof(const char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = -1;
  while (str[++i]);
  return (i);
}

static int	check_is_endend(char *line)
{
  int		i;

  if (line == NULL)
    return (0);
  i = -1;
  while (line[++i])
    if (line[i] == EOL_CHAR || line[i] == EOL_CHAR2 || line[i] == '\0')
	{
	  line[i] = 0;
	  return (1);
	}
  return (0);
}

static char	*init_line(char *buffer)
{
  char		*line;
  int		i;
  int		k;

  if (buffer == NULL)
    return (NULL);
  i = -1;
  while (buffer[++i] != EOL_CHAR && buffer[i] != EOL_CHAR2)
    {
      if (buffer[i] == '\0')
	return (NULL);
    }
  buffer[i] = 1;
  i++;
  line = my_malloc(sizeof(char) * (READ_SIZE + 1));
  my_memset(line, 0, sizeof(char) * (READ_SIZE + 1));
  k = -1;
  while (buffer[++k + i])
    line[k] = buffer[i + k];
  return (line);
}

static char	*my_copy(char *line1, const char *line2)
{
  char		*line3;
  int		l[3];

  l[0] = my_lenof(line1);
  l[1] = my_lenof(line2);
  line3 = my_malloc(sizeof(char) * (l[0] + l[1] + 1));
  my_memset(line3, 0, sizeof(char) * (l[0] + l[1] + 1));
  l[2] = -1;
  while (++l[2] < l[0])
    line3[l[2]] = line1[l[2]];
  l[2] = -1;
  while (++l[2] < l[1])
    line3[l[2] + l[0]] = line2[l[2]];
  free(line1);
  return (line3);
}

char		*get_next_line(const int fd)
{
  static char	*buffer = NULL;
  char		*line;
  int		ret;

  if (check_is_endend((line = init_line(buffer))))
    return (line);
  if (buffer == NULL)
    buffer = my_malloc(sizeof(char) * (READ_SIZE + 1));
  if ((ret = read(fd, buffer, READ_SIZE)) == -1)
    return (NULL);
  buffer[ret] = 0;
  (ret == 0) ? free(buffer) : (1);
  while (ret != 0)
    {
      line = my_copy(line, buffer);
      if (check_is_endend(line))
	return (line);
      buffer[(ret = read(fd, buffer, READ_SIZE))] = 0;
    }
  if (my_lenof(line) == 0)
    {
      free(line);
      return ((buffer = NULL));
    }
  return (line);
}
