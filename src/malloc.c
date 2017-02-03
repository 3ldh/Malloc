/*
** malloc.c for MALLOC in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 21:15:11 2017 bougon_p
** Last update Thu Feb  2 22:54:46 2017 bougon_p
*/

#include "block.h"

void		*start_heap = NULL;
pthread_mutex_t	mutex;

// Malloc ...
void		*_malloc(size_t size)
{
  t_block	block;
  t_block	last_block;

  size = align(size);
  if (!start_heap)
    {
      if ((block = add_heap(NULL, size)) == NULL)
	return (NULL);
      split_block(block, size);
      block->free = 0;
      start_heap = block;
    }
  else
    {
        last_block = start_heap;
        block = find_block(&last_block, size);
        if (block)
            split_block(block, size);
        else if ((block = add_heap(last_block, size)) == NULL)
            return (NULL);
        split_block(block, size);
        block->free = 0;
    }
  return (block->c);
}

void		*malloc(size_t size)
{
  void		*ptr;

  //  write(1, "deb malloc\n", 11);
  pthread_mutex_lock(&mutex);
  ptr = _malloc(size);
  pthread_mutex_unlock(&mutex);
  //  write(1, "end malloc\n", 11);
  return (ptr);
}
