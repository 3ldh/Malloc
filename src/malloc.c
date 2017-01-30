/*
** malloc.c for MALLOC in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 21:15:11 2017 bougon_p
** Last update Mon Jan 30 13:50:42 2017 bougon_p
*/

#include "block.h"

void *start_heap = NULL;

// Malloc ...
void		*malloc(size_t size)
{
  t_block	block;
  t_block	last_block;

  if (!start_heap)
    {
      if ((block = add_and_split(NULL, size)) == NULL)
	return (NULL);
      start_heap = block;
    }
  else
    {
      last_block = start_heap;
      block = find_block(&last_block, size);
      if (block)
	{
	  if (block->size - size >= BLOCK_SIZE +  MINIMAL_SIZE)
	    split_block(block, size);
	}
      else if ((block = add_and_split(last_block, size)) == NULL)
	return (NULL);
      block->free = 0;
    }
  return (block->c);
}
