/*
** main.c for  in /home/yohan/liste_chaine/A_star
**
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
**
** Started on  Mon Apr 17 09:15:55 2017 Yohan
** Last update Sun Apr 30 21:44:35 2017 Yohan
*/

#include <stdio.h>
#include <stdlib.h>
#include "parseur.h"

t_alg		add_new(t_alg new, t_graph *som)
{
  t_alg		tmp;

  if (!(tmp = malloc(sizeof(t_star))))
    return (NULL);
  tmp->next = som;
  tmp->last = new;
  return (tmp);
}

t_alg		dump_astar(t_graph *tmp, t_alg new)
{
  t_graph	*check;
  t_graph	*cnt;
  t_graph	*som;

  if (tmp == NULL)
    return (new);
  check = tmp->next[1];
  cnt = tmp;
  while (check != NULL)
    {
      som = check->prev;
      if (som != NULL && som->prev == NULL)
	{
	  som->prev = check;
	  if (!(new = add_new(new, som)))
	    return (NULL);
	}
      check->prev = cnt;
      check = check->next[0];
    }
  return (new);
}

int		check_way(t_alg open, char *exit)
{
  t_alg		tmp;

  tmp = open;
  while (tmp->next != NULL)
    {
      if (my_strcmp(tmp->next->name, exit) == 0)
	return (1);
      tmp = tmp->last;
    }
  return (0);
}

int		pathfinding(t_alg open, char *exit)
{
  t_graph	*tmp;
  t_alg		new;
  int		ret;

  ret = 0;
  while (1)
    {
      if (!(new = malloc(sizeof(t_star))))
	return (1);
      new->next = NULL;
      new->last = NULL;
      while (open != NULL)
	{
	  tmp = open->next;
	  new = dump_astar(tmp, new);
	  open = open->last;
	}
      if (ret == 1)
	return (0);
      if (new->next == NULL || new->last == NULL)
	return (1);
      open = new;
      ret = (check_way(open, exit) == 1) ? 1 : 0;
    }
  return (0);
}

int		my_astar(t_control *start, char *exit)
{
  t_graph	*graph;
  int		my_error;
  t_alg		open;

  graph = start->first;
  graph->prev = NULL;
  if ((open = malloc(sizeof(t_star))) == NULL)
    return (1);
  open->next = graph;
  open->last = NULL;
  my_error = pathfinding(open, exit);
  return (my_error);
}
