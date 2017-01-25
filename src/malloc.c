/*
** malloc.c for MALLOC in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 21:15:11 2017 bougon_p
** Last update Wed Jan 25 22:10:33 2017 bougon_p
*/

#include "block.h"

// Malloc ...
void	*malloc(size_t size)
{
  void	*ptr;

  if ((ptr = sbrk(size)) == (void *)-1)
    return (NULL);
  return (ptr);
}
