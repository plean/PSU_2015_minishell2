/*
** my_putnbr_base.c for  in /home/planch_j/rendu/CPE/CPE_2015_corewar/corewar/parsing/lib/my/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Wed Mar 23 15:19:31 2016 Jean PLANCHER
** Last update Sun Mar 27 15:46:18 2016 Jean PLANCHER
*/

#include "my.h"

void	my_putnbr_base(const char *str, int nb, int n)
{
  (nb / my_strlen(str) == 0) ? (1) :
      my_putnbr_base(str, nb / my_strlen(str), n);
  (nb < 0) ? write(n, "-", 1) : write(n, &str[nb % my_strlen(str)], 1);
}

void	my_putunbr_base(const char *str, unsigned int nb, int n)
{
  (nb / my_strlen(str) == 0) ? (1) :
      my_putnbr_base(str, nb / my_strlen(str), n);
  write(n, &str[nb % my_strlen(str)], 1);
}
