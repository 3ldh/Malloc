/*
** lib_malloc.h for MALLOC in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 21:24:10 2017 bougon_p
** Last update Mon Jan 30 18:09:27 2017 Sauvau Mathieu
*/

#ifndef LIB_MALLOC_H_
# define LIB_MALLOC_H_

# include <stddef.h>

/*
** Prototypes for the library Malloc
*/
void	*malloc(size_t);
void	free(void *);
void	*realloc(void *, size_t);
void	show_alloc_mem();

#endif /* !LIB_MALLOC_H_ */
