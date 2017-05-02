/*
** take_path.c for  in /home/yohan/CPE_2016_Lemin
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Tue Apr 25 15:03:10 2017 Yohan
** Last update Sun Apr 30 21:38:08 2017 Yohan
*/

#include <stdio.h>
#include <stdlib.h>
#include "parseur.h"
#include "basic.h"

t_path		add_start(t_path path, char *name)
{
  t_path	elem;

  if ((elem = malloc(sizeof(t_way))) == NULL)
    return (NULL);
  elem->name = name;
  elem->next = path;
  return (elem);
}

t_path		recover_path(t_graph *graph, t_path path, char *name)
{
  t_graph	*tmp;

  tmp = graph;
  while (tmp != NULL)
    {
      tmp = tmp->prev;
      if (tmp == NULL)
	return (NULL);
      if ((path = add_start(path, tmp->name)) == NULL)
	return (NULL);
      if (my_strcmp(tmp->name, name) == 0)
	break;
      tmp = tmp->prev;
    }
  return (path);
}

t_path		take_path(t_control *end,  char *entry)
{
  t_graph	*graph;
  t_path	path;

  graph = end->last;
  if ((path = malloc(sizeof(t_way))) == NULL)
    return (NULL);
  path->name = graph->name;
  path->next = NULL;
  if ((path = recover_path(graph, path, entry)) == NULL)
    return (NULL);
  return (path);
}
