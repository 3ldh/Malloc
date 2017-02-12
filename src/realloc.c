/*
** realloc.c for MALLOC in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 21:16:37 2017 bougon_p
** Last update Sun Feb 12 20:22:24 2017 bougon_p
*/

#include <string.h>
#include "block.h"
#include "lib_malloc.h"

/*
** Try right fusion to add allocated space to ptr
*/
bool		fusion_realloc(t_block block, size_t size)
{
  if (block->next && block->next->free == 1
      && block->size + block->next->size +
      BLOCK_SIZE > size)
    {
      fusion_right(block);
      if (block->size > size)
	split_block(block, size);
      return (true);
    }
  return (false);
}

void		*_realloc(void *ptr, size_t size, t_block block, void *new_ptr)
{
  size = ((size - 1) / MINIMAL_SIZE * MINIMAL_SIZE + MINIMAL_SIZE);
  if (block->size < size)
    {
      if (fusion_realloc(block, size))
	return (ptr);
    }
  else if (block->size > size)
    {
      split_block(block, size);
      return (ptr);
    }
  else
    return (ptr);
  if (!(new_ptr = malloc(size)))
    return (NULL);
  memcpy(new_ptr, ptr, block->size);
  free(ptr);
  return (new_ptr);
}

//realloc ...
void		*realloc(void *ptr, size_t size)
{
  t_block	block;
  void		*new_ptr;

  new_ptr = NULL;
  if (ptr && size == 0)
    return (free(ptr), ptr);
  if (!ptr)
    return (malloc(size));
  if (start_heap == NULL || !IS_ON_HEAP(ptr))
    return (ptr);
  block = (t_block)((char*)ptr - BLOCK_SIZE);
  if (block->addr != ptr)
    {
      return (ptr);
    }
  block = (t_block)((char *)ptr - BLOCK_SIZE);
  if (block->addr != ptr)
    {
      return (ptr);
    }
  return (_realloc(ptr, size, block, new_ptr));
}
