/*
** generic_list.h for DLIST in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 20:13:27 2017 bougon_p
** Last update Wed Jan 25 21:12:48 2017 bougon_p
*/

#ifndef GENERIC_DLIST_H_
# define GENERIC_DLIST_H_

# include <stdbool.h>

/*
** Types
*/


typedef struct  s_node
{
    void            *value;
    struct s_node   *next;
    struct s_node   *prev;
}               t_node;

typedef t_node   *t_list;

/*
** Functions
*/

/* Informations */

unsigned int    list_get_size(t_list list);
bool          list_is_empty(t_list list);

typedef void    (*t_value_displayer)(void *value);

void            list_dump(t_list list, t_value_displayer val_disp);

/* Modification */

bool  list_add_elem_at_front(t_list *front_ptr, void *elem);
bool  list_add_elem_at_back(t_list *front_ptr, void *elem);
bool  list_add_elem_at_position(t_list *front_ptr, void *elem,
				  unsigned int position);

bool  list_del_elem_at_front(t_list *front_ptr);
bool  list_del_elem_at_back(t_list *front_ptr);
bool  list_del_elem_at_position(t_list *front_ptr, unsigned int position);

void    list_clear(t_list *front_ptr);

/* Value Access */

void    *list_get_elem_at_front(t_list list);
void    *list_get_elem_at_back(t_list list);
void    *list_get_elem_at_position(t_list list, unsigned int position);

/* Node Access */

typedef int (*t_value_comparator)(void *first, void *second);

t_node  *list_get_first_node_with_value(t_list list, void *value,
					t_value_comparator val_comp);

#endif /* !GENERIC_DLIST_H_ */
