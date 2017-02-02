/*
** calloc.c for malloc in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Feb  1 15:55:07 2017 bougon_p
** Last update Wed Feb  1 15:58:04 2017 bougon_p
*/

#include <strings.h>
#include "lib_malloc.h"

void	*calloc(size_t nmemb, size_t size)
{
  void	*ptr;

  if (!(ptr = malloc(nmemb * size)))
    return (NULL);
  bzero(ptr, nmemb * size);
  return (ptr);
}
