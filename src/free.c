/*
** free.c for MALLOC in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 21:16:51 2017 bougon_p
** Last update Wed Feb  1 16:02:53 2017 Sauvau Mathieu
*/

#include "block.h"

void	fusion_right(t_block to_fusion)
{
  //  write(1, "deb fusion right\n", 17);
  if (to_fusion->next->next)
    to_fusion->next->next->prev = to_fusion;
  to_fusion->size += to_fusion->next->size + BLOCK_SIZE;
  to_fusion->next = to_fusion->next->next;
  //  write(1, "end fusion right\n", 17);
}

void	fusion_left(t_block to_fusion)
{
  //  write(1, "deb fusion left\n", 16);
  to_fusion = to_fusion->prev;
  if (to_fusion->next && to_fusion->next->free)
    fusion_right(to_fusion);
  //  write(1, "end fusion left\n", 16);
}

//Just leave 42 Bytes for the sake of the world !
void		_free(void *ptr)
{
  t_block	block;
  
  if (!IS_ON_HEAP(ptr))
    return;
  block = (t_block)((char *)ptr - BLOCK_SIZE);
  if (block->addr != ptr)
    return;
  block->free = 1;
  /* if (block->prev && block->prev->free) */
  /*   fusion_left(block); */
  if (block->next && block->next->free)
    fusion_right(block);
}

void		free(void *ptr)
{
  //write(1, "deb free\n", 9);
  pthread_mutex_lock(&mutex);
  (void)ptr;
  _free(ptr);
  pthread_mutex_unlock(&mutex);
  //  write(1, "end free\n", 9);
}
