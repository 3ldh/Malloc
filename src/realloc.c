/*
** realloc.c for MALLOC in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 21:16:37 2017 bougon_p
** Last update Mon Jan 30 18:31:30 2017 bougon_p
*/

#include <string.h>
#include "block.h"
#include "lib_malloc.h"

/*
** Check if the fusion will be possible
*/
bool		fusion_is_possible(t_block block, size_t size)
{
  t_block	tmp;
  size_t	current_size;

  tmp = block->next;
  current_size = block->size;
  while (current_size < size && tmp->free == 1)
    {
      current_size += tmp->size;
      tmp = tmp->next;
    }
  return (current_size > size);
}

/*
** Try right successive fusions to add allocated space to ptr
*/
bool		fusion_realloc(t_block block, size_t size)
{
  t_block	tmp;

  if (!fusion_is_possible(block, size))
    return (false);
  tmp = block->next;
  while (block->size < size && tmp->free == 1)
    {
      block->next = tmp->next;
      tmp->next->prev = block;
      block->size += tmp->size + BLOCK_SIZE;
      tmp = tmp->next;
    }
  return (true);
}

//realloc ...
void		*realloc(void *ptr, size_t size)
{
  t_block	block;
  void		*new_ptr;

  if (!IS_ON_HEAP(ptr))
    return (NULL);
  block = ptr - BLOCK_SIZE;
  if (block->addr != ptr)
    return (NULL);
  if (block->size > size)
    {
      if (fusion_realloc(block, size))
	return (ptr);
    }
  else if (block->size < size)
    split_block(block, size);
  else
    return (ptr);
  if (!(new_ptr = malloc(size)))
    return (NULL);
  memcpy(new_ptr, ptr, block->size);
  free(block->addr);
  return (new_ptr);
}
