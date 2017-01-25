/*
** block.h for BLOCK in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 19:55:54 2017 bougon_p
** Last update Wed Jan 25 21:29:00 2017 bougon_p
*/

#ifndef BLOCK_H_
# define BLOCK_H_

# include <stddef.h>
# include <stdbool.h>
# include "generic_dlist.h"

typedef struct s_block t_block;

typedef struct	s_block
{
  bool		full;
  void		*addr;
}		t_block;

#endif /* !BLOCK_H_ */
