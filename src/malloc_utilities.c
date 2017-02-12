/*
** malloc_utilities.c for  in /home/sauvau_m/rendu/PSU_2016_malloc/include
**
** Made by Sauvau Mathieu
** Login   <sauvau_m@epitech.net>
**
** Started on  Thu Jan 26 12:52:43 2017 Sauvau Mathieu
** Last update Sun Feb 12 15:46:17 2017 Sauvau Mathieu
*/

#include "block.h"

size_t		align_pagesize(size_t size)
{
  return ((size - 1) / getpagesize() * getpagesize() + getpagesize());
}

t_block		add_heap(t_block last_block, size_t size)
{
  t_block	b;

  b = sbrk(0);
  if (sbrk(BLOCK_SIZE + align_pagesize(size)) == (void*)-1)
    return (NULL);
  b->size = align_pagesize(size);
  b->free = 1;
  b->next = NULL;
  b->prev = last_block;
  b->addr = b->c;
  if (last_block)
  {
      last_block->next = b;
      if (last_block->free == 1)
      {
          fusion_right(last_block);
          return (last_block);
      }
  }
  return (b);
}

t_block		find_block(t_block *last_block, size_t size)
{
  t_block	block;

  block = start_heap;
  while (block && !(block->free && block->size >= size))
    {
      *last_block = block;
      block = block->next;
    }
  return (block);
}

bool		split_block(t_block block, size_t size)
{
  t_block	b;

  if (block->size - size >= BLOCK_SIZE + MINIMAL_SIZE)
    {
      b = (t_block)(block->c + size);
      b->size = block->size - size - BLOCK_SIZE;
      b->free = 1;
      b->next = block->next;
      b->prev = block;
      b->addr = b->c;
      block->size = size;
      block->next = b;
      if (b->next)
	b->next->prev = b;
      return (true);
    }
  return (false);
}
