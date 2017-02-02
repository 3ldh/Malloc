/*
** malloc_utilities.c for  in /home/sauvau_m/rendu/PSU_2016_malloc/include
**
** Made by Sauvau Mathieu
** Login   <sauvau_m@epitech.net>
**
** Started on  Thu Jan 26 12:52:43 2017 Sauvau Mathieu
** Last update Wed Feb  1 14:55:38 2017 bougon_p
*/

#include "block.h"

size_t		align_pagesize(size_t size)
{
  return ((size - 1) / getpagesize() * getpagesize() + getpagesize());
}

t_block		add_heap(t_block last_block, size_t size)
{
  t_block	b;

  //  write(1, "deb add heap\n", 13);
  b = sbrk(0);
  if (sbrk(BLOCK_SIZE + align_pagesize(size)) == (void*)-1)
      return NULL;
  b->size = align_pagesize(size);
  b->free = 1;
  b->addr = b->c;
  b->next = NULL;
  b->prev = last_block;
  if (last_block)
    last_block->next = b;
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
      b->addr = b->c;
      b->next = block->next;
      b->prev = block;
      block->size = size;
      block->next = b;
      if (b->next)
	b->next->prev = b;
      return (true);
    }
  return (false);
}

t_block		add_and_split(t_block block, size_t size)
{
  //  write(1, "deb add and split\n", 19);
  if (!start_heap)
    {
      if ((block = add_heap(NULL, size)) == NULL)
	return (NULL);
    }
  else
    {
      if ((block = add_heap(block, size)) == NULL)
	return (NULL);
    }
  split_block(block, size);
  //  write(1, "end add and split\n", 19);
  return (block);
}
