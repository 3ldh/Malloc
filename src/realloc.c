/*
** realloc.c for MALLOC in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 21:16:37 2017 bougon_p
** Last update Tue Jan 31 18:17:35 2017 Sauvau Mathieu
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

//realloc ...
void		*realloc(void *ptr, size_t size)
{
  t_block	block;
  void		*new_ptr;

  if (!ptr)
    return (malloc(size));
  if (!IS_ON_HEAP(ptr))
    return (NULL);
  block = ptr - BLOCK_SIZE;
  if (block->addr != ptr)
    return (NULL);
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
