/*
** show_alloc_mem.c for MALLOC in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 21:18:09 2017 bougon_p
** Last update Sun Jan 29 14:46:28 2017 bougon_p
*/

#include <stdio.h>
#include "block.h"

/*
** Dump the allocated space of memory
*/
void		show_alloc_mem()
{
  t_block	tmp;

  printf("break : %p\n", GET_BREAK);
  tmp = start;
  while (tmp)
    {
      printf("%p - %p : %lu bytes\n", tmp, tmp + tmp->size, tmp->size);
      tmp = tmp->next;
    }
}
