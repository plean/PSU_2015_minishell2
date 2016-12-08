/*
** flags.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Mon Apr 11 17:36:59 2016 Jean PLANCHER
** Last update Mon Apr 11 17:52:01 2016 Jean PLANCHER
*/

#include "my.h"

void	aff_version(const char *str)
{
  write(1, &str[2], my_strlen(&str[2]));
  write(1, " version 2.0.3 (plean) 2016-04-11\n", 34);
}

void	aff_help(const char *str)
{
  aff_version(str);
  write(1, "\nUsage:\tmysh [option]\n", 22);
  write(1, "mysh option:\n", 13);
  write(1, "\t-h, --help\tprint this message and exit.\n", 43);
  write(1, "\t-v, --version\tprint the version shell variable and exit.\n", 58);
}
