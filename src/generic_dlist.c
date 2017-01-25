/*
** generic_list.c for list in /home/bougon_p/rendu/TEK2/cpp_d02a/ex02
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Jan  5 19:15:31 2017 bougon_p
** Last update Wed Jan 25 21:13:01 2017 bougon_p
*/

#include <stdlib.h>
#include <stdio.h>
#include "generic_dlist.h"

unsigned int	list_get_size(t_list list)
{
  int		i = 0;

  while (list != NULL)
    {
      list = list->next;
      i++;
    }
  return (i);
}

bool		list_is_empty(t_list list)
{
  if (list == NULL)
    return (true);
  return (false);
}

void		list_dump(t_list list, t_value_displayer val_disp)
{
  while (list != NULL)
    {
      val_disp(list->value);
      list = list->next;
    }
}

bool		list_add_elem_at_front(t_list *front_ptr, void *elem)
{
  t_node	*new;

  if (!(new = malloc(sizeof(t_node))))
    return (false);
  new->value = elem;
  new->next = *front_ptr;
  new->prev = NULL;
  *front_ptr = new;
  return (true);
}

bool		list_add_elem_at_back(t_list *front_ptr, void *elem)
{
  t_list	tmp;
  t_node	*new;

  if (*front_ptr == NULL)
    return (list_add_elem_at_front(front_ptr, elem));

  tmp = *front_ptr;
  while (tmp->next != NULL)
    tmp = tmp->next;

  if (!(new = malloc(sizeof(t_node))))
    return (false);
  new->value = elem;
  tmp->next = new;
  new->next = NULL;
  new->prev = tmp;
  return (true);
}

bool		list_add_elem_at_position(t_list *front_ptr,
					  void *elem, unsigned int position)
{
  t_list	tmp;
  t_node	*new;
  unsigned int	i = 0;

  if (*front_ptr == NULL)
    return (false);

  tmp = *front_ptr;
  while (i++ < position - 1 && tmp->next != NULL)
    tmp = tmp->next;
  if (i < position - 1)
    return (false);

  if (!(new = malloc(sizeof(t_node))))
    return (false);
  new->value = elem;
  new->next = tmp->next;
  new->prev = tmp;
  tmp->next->prev = new;
  tmp->next = new;
  return (true);
}

bool		list_del_elem_at_front(t_list *front_ptr)
{
  t_node	*tmp;

  if (*front_ptr == NULL)
    return (false);
  tmp = (*front_ptr)->next;
  free(*front_ptr);
  tmp->prev = NULL;
  *front_ptr = tmp;
  return (true);
}

bool  list_del_elem_at_back(t_list *front_ptr)
{
  t_list	tmp;

  if (*front_ptr == NULL)
    return (false);

  tmp = *front_ptr;
  while (tmp->next->next != NULL)
    tmp = tmp->next;
  free(tmp->next);
  tmp->next = NULL;
  return (true);
}

bool  list_del_elem_at_position(t_list *front_ptr, unsigned int position)
{
  t_list	tmp;
  t_node	*link;
  unsigned int	i = 0;

  if (*front_ptr == NULL)
    return (false);
  if (position == 0)
    return (list_del_elem_at_front(front_ptr));

  tmp = *front_ptr;
  while (i++ < position - 1 && tmp->next->next != NULL)
    tmp = tmp->next;
  if (i < position - 1)
    return (false);

  link = tmp->next->next;
  free(tmp->next);
  tmp->next = link;
  link->prev = tmp;
  return (true);
}

void   *list_get_elem_at_front(t_list list)
{
  if (list == NULL)
    return (0);
  return (list->value);
}

void   *list_get_elem_at_back(t_list list)
{
  if (list == NULL)
    return (0);
  while (list->next != NULL)
    list = list->next;
  return (list->value);
}

void   *list_get_elem_at_position(t_list list, unsigned int position)
{
  unsigned int	i = 0;

  if (list == NULL)
    return (0);
  while (i++ < position && list->next != NULL)
    list = list->next;
  if (i < position)
    return (0);
  return (list->value);
}

void		list_clear(t_list *front_ptr)
{
  t_list	tmp;
  t_list	tmp2;

  while (tmp)
    {
      tmp2 = tmp->next;
      free(tmp);
      tmp = tmp2;
      tmp = tmp->next;
    }
  *front_ptr = NULL;
}

t_node  *list_get_first_node_with_value(t_list list,
					void *value,
					t_value_comparator val_comp)
{
   if (list == NULL)
    return (NULL);
   while (list->next != NULL && val_comp(value, list->value))
     list = list->next;
   if (list->next == NULL && val_comp(value, list->value))
     return (NULL);
   return (list);
}
