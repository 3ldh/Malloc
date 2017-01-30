/*
** my_putnbr_base.c for  in /home/sauvau_m/rendu/PSU_2016_malloc/src
** 
** Made by Sauvau Mathieu
** Login   <sauvau_m@epitech.net>
** 
** Started on  Mon Jan 30 17:44:09 2017 Sauvau Mathieu
** Last update Mon Jan 30 18:11:42 2017 Sauvau Mathieu
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>

void		my_putnbr_base(unsigned int nb, char *base)
{
  unsigned int	l_base;
  unsigned int	mod;
  unsigned int	r;

  l_base = strlen(base);
  mod = nb % l_base;
  r = (nb - mod) / l_base;
  if (nb >= l_base - 1 && r != 0)
    my_putnbr_base(r, base);
  write(1, &base[mod], 1);
}

void		my_putnbr_base_l(unsigned long nb, char *base)
{
  unsigned long	l_base;
  unsigned long	mod;
  unsigned long	r;

  l_base = strlen(base);
  mod = nb % l_base;
  r = (nb - mod) / l_base;
  if (nb >= l_base - 1 && r != 0)
    my_putnbr_base_l(r, base);
  write(1, &base[mod], 1);
  return ;
}
