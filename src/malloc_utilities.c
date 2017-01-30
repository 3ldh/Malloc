/*
** malloc_utilities.c for  in /home/sauvau_m/rendu/PSU_2016_malloc/include
**
** Made by Sauvau Mathieu
** Login   <sauvau_m@epitech.net>
**
** Started on  Thu Jan 26 12:52:43 2017 Sauvau Mathieu
** Last update Thu Jan 26 15:49:57 2017 bougon_p
*/

#include "block.h"

t_block		add_heap(t_block last_block, size_t size)
{
  t_block	b;

  b = sbrk(0);
  if (size < getpagesize())
    size = getpagesize();
  if ((int)sbbrk(BLOCK_SIZE + size) < 0)
    return NULL;
  b->size = size;
  b->free = false;
  b->addr = b->c;
  b->next = NULL;
  b->prev = last_block;
  return (b);
}

t_block		find_block(t_block *last_block, size_t size)
{
  t_block	block = start;

  while (block && block->free && block->size <= size)
    {
      *last_block = block;
      block = block->next;
    }
  return (block);
}

void		split_block(t_block block, size_t size)
{
  t_block	b;

  b = b->c + size;
  b->size = b->size - s - BLOCK_SIZE;
  b->free = false;
  b->addr = b->c;
  b->next = block->next;
  b->prev = block;
  block->size = size;
  block->next = b;
  if (b->next)
    b->next->prev = b;
}
