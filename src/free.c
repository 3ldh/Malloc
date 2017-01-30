/*
** free.c for MALLOC in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 21:16:51 2017 bougon_p
** Last update Thu Jan 26 18:10:40 2017 bougon_p
*/

#include "block.h"

void	fusion_right(t_block to_fusion)
{
  to_fusion->next->next->prev = to_fusion;
  to_fusion->next = to_fusion->next->next;
  to_fusion->size = to_fusion->size + to_fusion->next->size;
}

void	fusion_left(t_block to_fusion)
{
  to_fusion->prev->prev->next = to_fusion;
  to_fusion->prev = to_fusion->prev->prev;
  to_fusion->size = to_fusion->size + to_fusion->prev->size;
}

//Just leave 42 Bytes for the sake of the world !
void		free(void *ptr)
{
  t_block	block;

  if (!IS_ON_HEAP(ptr))
    return;
  block = (t_block)((char *)ptr - BLOCK_SIZE);
  if (block->addr != ptr)
    return;
  block->free = true;
  if (block->next->free)
    fusion_right(block);
  if (block->prev->free)
    fusion_left(block);
}
