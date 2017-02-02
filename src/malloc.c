/*
** malloc.c for MALLOC in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 21:15:11 2017 bougon_p
** Last update Wed Feb  1 21:16:28 2017 bougon_p
*/

#include "block.h"

void		*start_heap = NULL;
pthread_mutex_t	mutex;

// Malloc ...
void		*_malloc(size_t size)
{
  t_block	block;
  t_block	last_block;

  size = ((size - 1) / MINIMAL_SIZE * MINIMAL_SIZE + MINIMAL_SIZE);
  if (!start_heap)
    {
      if ((block = add_and_split(NULL, size)) == NULL)
	return (NULL);
      block->free = 0;
      start_heap = block;
    }
  else
    {
      last_block = start_heap;
      block = find_block(&last_block, size);
      if (block)
	split_block(block, size);
      else if ((block = add_and_split(last_block, size)) == NULL)
	return (NULL);
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
