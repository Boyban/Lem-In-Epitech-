/*
** display.c for Project-Master in /home/Swann/tek1/CPE_2016_Lemin/src
** 
** Made by Swann
** Login   <Swann@epitech.eu>
** 
** Started on  Fri Apr 28 18:27:22 2017 Swann
** Last update Sun Apr 30 21:18:46 2017 Swann
*/

#include "parseur.h"
#include "basic.h"

void	display_ant(int nb_ant)
{
  my_putstr(ANT);
  my_put_nbr(nb_ant);
  my_putchar('\n');
  my_putstr(ROOMS);
}

void	my_putstr_nb(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != c)
    my_putchar(str[i++]);
  my_putchar('\n');
}
