/*
** my_put_nbr.c for  in /home/sauvau_m/rendu/PSU_2016_malloc/src
** 
** Made by Sauvau Mathieu
** Login   <sauvau_m@epitech.net>
** 
** Started on  Mon Jan 30 17:44:16 2017 Sauvau Mathieu
** Last update Mon Jan 30 18:12:35 2017 Sauvau Mathieu
*/

#include <stdio.h>
#include <unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

long		my_put_nbr(long long nb)
{
  long long	div;

  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= 10)
    {
      div = nb % 10;
      nb = (nb - div) / 10;
      my_put_nbr(nb);
      my_putchar(div + '0');
    }
  else
    my_putchar(nb % 10 + '0');
  return (nb);
}
