/*
** list.c for  in /home/planch_j/rendu/CPE/CPE_2015_corewar/corewar/parsing/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Mar 27 06:14:14 2016 Jean PLANCHER
** Last update Sun Apr  3 16:11:31 2016 Jean PLANCHER
*/

#include "my.h"

t_list		*create_list(void)
{
  t_list	*list;
  list = my_malloc(sizeof(t_list));
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return (list);
}

void		add_element_b(t_list **list, void *data)
{
  t_element	*tmp;

  tmp = my_malloc(sizeof(t_element));
  tmp->data = data;
  tmp->next = (*list)->first;
  if (tmp->next)
    tmp->next->prev = tmp;
  tmp->prev = NULL;
  (*list)->first = tmp;
  if ((*list)->last == NULL)
    (*list)->last = tmp;
  (*list)->length++;
}

void		add_element_e(t_list **list, void *data)
{
  t_element	*tmp;

  tmp = my_malloc(sizeof(t_element));
  tmp->data = data;
  tmp->prev = (*list)->last;
  if ((*list)->last)
    (*list)->last->next = tmp;
  (*list)->last = tmp;
  tmp->next = NULL;
  if ((*list)->first == NULL)
    (*list)->first = tmp;
  (*list)->length++;
}

void		del_elem(t_list **list, t_element *elem)
{
  t_element	*tmp;
  t_env		*env;

  tmp = elem;
  env = (t_env *)tmp->data;
  free(env->env);
  free(env->data);
  (tmp->prev) ? tmp->prev->next = tmp->next : ((*list)->first = tmp->next);
  (tmp->next) ? tmp->next->prev = tmp->prev : ((*list)->last = tmp->prev);
  free(tmp);
  tmp = NULL;
}

void		del_list(t_list **list)
{
  t_element	*tmp;
  t_env		*env;

  while ((*list)->first != NULL)
    {
      tmp = (*list)->first->next;
      env = (t_env *)(*list)->first->data;
      free(env->env);
      free(env->data);
      free(env);
      free((*list)->first);
      (*list)->first = tmp;
      (*list)->length--;
    }
  free((*list));
}
