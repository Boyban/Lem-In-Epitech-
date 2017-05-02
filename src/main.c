/*
** main.c for Lemin in /home/tekos/delivery/CPE_2016_Lemin/src/
**
** Made by Clement Quillateau
** Login   <clement.quillateau@epitech.eu>
**
** Started on  Mon Apr 10 17:05:29 2017 Clement Quillateau
** Last update Sun Apr 30 21:09:40 2017 Yohan
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "astar.h"

t_ant		*add_path_start(t_ant *ant, char *str, int i)
{
  t_ant		*elem;

  if ((elem = malloc(sizeof(t_ant))) == NULL)
    return (NULL);
  elem->path = str;
  elem->index = i;
  elem->next = ant;
  return (elem);
}

void		aff_list(t_ant *elem)
{
  t_ant		*tmp;

  tmp = elem;
  while (tmp != NULL)
    {
      my_putchar('P');
      my_put_nbr(tmp->index);
      my_putchar('-');
      my_putstr_backn(tmp->path);
      tmp = tmp->next;
      if (tmp != NULL)
	my_putchar(' ');
    }
  my_putchar('\n');
}

void		aff_ant(int i, t_path path)
{
  t_path	tmp;
  t_ant		*elem;

  tmp = path->next;
  elem = NULL;
  while (i != 0 && tmp->next != NULL)
    {
      elem = add_path_start(elem, tmp->name, i);
      tmp = tmp->next;
      --i;
    }
  if (elem != NULL)
    aff_list(elem);
}

void	finish(t_path path, int nb)
{
  t_path	tmp;
  int		i;

  i = 1;
  tmp = path;
  my_putstr("#moves");
  while (i != nb)
    {
      aff_ant(i, tmp);
      ++i;
    }
  while (tmp->next != NULL)
    {
      if (tmp != NULL && tmp->next != NULL)
	aff_ant(i, tmp);
      tmp = tmp->next;
    }
}

int		main(NOUSE int ac, NOUSE char **av)
{
  t_control	*graph;

  if (!(graph = parseur()))
    return (84);
  return (0);
}
