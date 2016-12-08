/*
** list.h for  in /home/planch_j/rendu/CPE/CPE_2015_corewar/corewar/parsing/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Mar 27 04:31:11 2016 Jean PLANCHER
** Last update Tue Apr 12 00:52:21 2016 Jean PLANCHER
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct	s_env
{
  char		*env;
  char		*data;
}		t_env;

typedef struct		s_element
{
  void			*data;
  struct s_element	*next;
  struct s_element	*prev;
}			t_element;

typedef struct	s_list
{
  int		length;
  t_element	*first;
  t_element	*last;
}		t_list;

/*
** List
*/

t_list		*create_list(void);
void		del_elem(t_list **list, t_element *elem);
void		add_element_e(t_list **list, void *data);
void		add_element_b(t_list **list, void *data);
void		del_list(t_list **list);

/*
** Shell
*/

t_element	*find_env(t_list *list, const char *str);
t_list		*get_alias(t_element *new_elem);

#endif /* !LIST_H_ */
