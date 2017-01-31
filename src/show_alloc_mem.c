/*
** show_alloc_mem.c for MALLOC in /home/bougon_p/rendu/TEK2/PSU_2016_malloc
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 25 21:18:09 2017 bougon_p
** Last update Mon Jan 30 19:56:27 2017 Sauvau Mathieu
*/

#include <stdio.h>
#include "block.h"

/*
** Dump the allocated space of memory
*/
void		show_alloc_mem()
{
  t_block	tmp;

  write(1, "break : ", 8);
  write(1, "0x", 2);
  my_putnbr_base_l((unsigned long)GET_BREAK, "0123456789ABCDEF");
  write(1, "\n", 1);
  tmp = start_heap;
  while (tmp)
    {
      if (tmp->free == 0)
	{
	  write(1, "0x", 2);
	  my_putnbr_base_l((unsigned long)tmp->addr, "0123456789ABCDEF");
	  write(1, " - 0x", 5);
	  my_putnbr_base_l((unsigned long)(tmp->addr + tmp->size),
			   "0123456789ABCDEF");
	  write(1, " : ", 3);
	  my_put_nbr(tmp->size);
	  write(1, " bytes\n ", 7);
	}
      tmp = tmp->next;
    }
}
