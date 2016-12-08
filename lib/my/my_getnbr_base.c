/*
** my_getnbr_base.c for  in /home/planch_j/rendu/CPE/CPE_2015_corewar/corewar/parsing/lib/my/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Wed Mar 23 15:19:12 2016 Jean PLANCHER
** Last update Fri Mar 25 23:29:01 2016 Jean PLANCHER
*/

#include "my.h"

int	base_pos(char c, const char *base)
{
  int	i;

  i = -1;
  while (base[++i] != c && base[i]);
  return (i);
}

int	my_getnbr_base(const char *str, const char *base)
{
  int	i;
  int	nb;

  nb = 0;
  if (str == NULL)
    return (0);
  i = -1 + (str[0] == '-');
  while (str[++i])
    nb = nb * my_strlen(base) + base_pos(str[i], base);
  return (nb * (((str[0] != '-') << 1) - 1));
}

unsigned int	my_getunbr_base(const char *str, const char *base)
{
  unsigned int	nb;
  int		i;

  nb = 0;
  if (str == NULL)
    return (0);
  i = -1;
  while (str[++i])
    nb = nb * my_strlen(base) + base_pos(str[i], base);
  return (nb);
}
