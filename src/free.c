/*
** free.c for MALLOC in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 21:16:51 2017 bougon_p
** Last update Sun Feb 12 20:29:11 2017 bougon_p
*/

#include "block.h"

void	check_last_block(t_block block)
{
  if (!block->next)
  {
      while ((block->size + BLOCK_SIZE) / getpagesize() > 0)
      {
          if (split_block(block, block->size - getpagesize()))
              block->next = NULL;
          else if (block->prev)
              block->prev->next = NULL;
          else
              start_heap = NULL;
          sbrk(getpagesize() * -1);
      }
  }
}

void	fusion_right(t_block to_fusion)
{
    if (!to_fusion || !to_fusion->next
        || to_fusion->next->free != 1)
        return ;
  if (to_fusion->next->next)
    to_fusion->next->next->prev = to_fusion;
  to_fusion->size += to_fusion->next->size + BLOCK_SIZE;
  to_fusion->next = to_fusion->next->next;
}

void	fusion_left(t_block *to_fusion)
{
  (*to_fusion) = (*to_fusion)->prev;
  if ((*to_fusion) && (*to_fusion)->next && (*to_fusion)->next->free)
    fusion_right(*to_fusion);
}

/*
** Just leave 42 Bytes for the sake of the world !
*/
void		_free(void *ptr)
{
  t_block	block;

  if (start_heap == NULL || !IS_ON_HEAP(ptr))
    return ;
  block = (t_block)((char *)ptr - BLOCK_SIZE);
  if (block->addr != ptr)
    return ;
  block->free = 1;
  if (block->next && block->next->free)
    fusion_right(block);
}

/*
** Add this in the previous function
** if (block->prev && block->prev->free)
** fusion_left(&block);
** check_last_block(block);
*/
void		free(void *ptr)
{
  pthread_mutex_lock(&mutex);
  (void)ptr;
  _free(ptr);
  pthread_mutex_unlock(&mutex);
}
