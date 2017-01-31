/*
** block.h for BLOCK in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 19:55:54 2017 bougon_p
** Last update Tue Jan 31 17:14:20 2017 Sauvau Mathieu
*/

#ifndef BLOCK_H_
# define BLOCK_H_

# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>
# include <unistd.h>
# include <pthread.h>

# if UINTPTR_MAX == 0xffffffff
/* 32-bit */
#  define BLOCK_SIZE 20
#  define MINIMAL_SIZE 4
# elif UINTPTR_MAX == 0xffffffffffffffff
/* 64-bit */
#  define BLOCK_SIZE 40
#  define MINIMAL_SIZE 8
# else
/* wtf */
# endif

# define GET_BREAK sbrk(0)

typedef struct s_block *t_block;

struct		s_block
{
  size_t	size;
  t_block	next;
  t_block	prev;
  int		free;
  void		*addr;
  char		c[1];
};

void        fusion_right(t_block);
t_block		add_heap(t_block last_block, size_t size);
t_block		find_block(t_block *last_block, size_t size);
void		split_block(t_block block, size_t size);
t_block		add_and_split(t_block block, size_t size);
long		my_put_nbr(long long nb);
void		my_putnbr_base_l(unsigned long nb, char *base);

extern void		*start_heap;
extern pthread_mutex_t	mutex;

# define IS_ON_HEAP(ptr) (ptr < start_heap || ptr > sbrk(0)) ? false : true

#endif /* !BLOCK_H_ */
