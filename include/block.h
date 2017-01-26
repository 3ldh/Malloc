/*
** block.h for BLOCK in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 19:55:54 2017 bougon_p
** Last update Thu Jan 26 11:16:23 2017 Sauvau Mathieu
*/

#ifndef BLOCK_H_
# define BLOCK_H_

# include <stddef.h>
# include <stdbool.h>
# include <unistd.h>

# define BLOCK_SIZE 17

typedef struct s_block *t_block;

struct		s_block
{
  size_t	size;
  t_block	next;
  t_block	prev;
  bool		free;
  void		*addr;
  char		c[1];
};

void		*start = NULL;

#endif /* !BLOCK_H_ */
