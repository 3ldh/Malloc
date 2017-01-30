/*
** malloc_utilities.c for  in /home/sauvau_m/rendu/PSU_2016_malloc/include
**
** Made by Sauvau Mathieu
** Login   <sauvau_m@epitech.net>
**
** Started on  Thu Jan 26 12:52:43 2017 Sauvau Mathieu
** Last update Mon Jan 30 13:10:12 2017 bougon_p
*/

#include "block.h"

size_t		get_right_pagesize(size_t size)
{
  return ((size - 1) / getpagesize() * getpagesize() + getpagesize());
}

t_block		add_heap(t_block last_block, size_t size)
{
  t_block	b;

  b = sbrk(0);
  if (sbrk(BLOCK_SIZE + get_right_pagesize(size)) == (void*)-1)
    return NULL;
  b->size = size;
  b->free = 1;
  b->addr = b->c;
  b->next = NULL;
  b->prev = last_block;
  return (b);
}

t_block		find_block(t_block *last_block, size_t size)
{
  t_block	block;

  block = start;
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

  b = (t_block)(block->c + size);
  b->size = b->size - size - BLOCK_SIZE;
  b->free = 0;
  b->addr = b->c;
  b->next = block->next;
  b->prev = block;
  block->size = size;
  block->next = b;
  if (b->next)
    b->next->prev = b;
}

t_block		add_and_split(t_block block, size_t size)
{
  if ((block = add_heap(NULL, size)) == NULL)
    return (NULL);
  split_block(block, size);
  return (block);
}
