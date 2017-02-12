/*
** malloc.c for MALLOC in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 21:15:11 2017 bougon_p
** Last update Sun Feb 12 20:30:43 2017 bougon_p
*/

#include "block.h"

void		*start_heap = NULL;
pthread_mutex_t	mutex;

/*
** Malloc ...
*/
void		*_malloc(size_t size)
{
  t_block	block;
  t_block	last_block;

  if (!start_heap)
    {
      if ((block = add_heap(NULL, size)) == NULL)
	return (NULL);
      split_block(block, size);
      start_heap = block;
      block->free = 0;
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

  pthread_mutex_lock(&mutex);
  if ((int)size <= 0)
    return (NULL);
  size = align(size);
  ptr = _malloc(size);
  pthread_mutex_unlock(&mutex);
  return (ptr);
}
