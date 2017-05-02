/*
** graph.c for Lemin in /home/swann/epitech/CPE_2016_Lemin/src
**
** Made by Giboureau
** Login   <swann@epitech.net>
**
** Started on  Tue Apr 18 11:40:52 2017 Giboureau
** Last update Sun Apr 30 21:38:00 2017 Swann
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "basic.h"
#include "graph.h"

t_control	*create_graph()
{
  t_control	*graph;

  if (!(graph = malloc(sizeof(t_control))))
    return (NULL);
  graph->first = NULL;
  graph->last = NULL;
  graph->length = 0;
  return (graph);
}

t_graph		*create_elem(char *data, int nb)
{
  t_graph	*link;
  int		i;

  i = 0;
  if (!(link = malloc(sizeof(t_graph)))
      || !(link->next = malloc(sizeof(t_graph *) * (nb + 2)))
      || !(link->prev = malloc(sizeof(t_graph))))
    return (NULL);
  link->name = data;
  while (nb == 0 && i < 2)
    {
      if (!(link->next[i] = malloc(sizeof(t_graph))))
	return (NULL);
      link->next[i++] = NULL;
    }
  if (nb == 1)
    {
      if (!(link->next[0] = malloc(sizeof(t_graph))))
	return (NULL);
      link->next[0] = NULL;
    }
  link->prev = NULL;
  return (link);
}

bool	push_vertex(t_control *graph, char *name, int nb)
{
  t_graph	*tmp;
  t_graph	*new;

  if (!(new = create_elem(name, 0)))
    return (false);
  tmp = graph->first;
  if (graph->length == 0 || nb == 1)
    graph->first = new;
  if (nb == -1)
    graph->last = new;
  if (graph->length != 0)
    {
      while (tmp->next[0] != NULL)
	tmp = tmp->next[0];
      tmp->next[0] = new;
    }
  graph->length++;
  return (true);
}

void	connect_edge(t_control *graph, t_graph *new, char *link)
{
  t_graph	*tmp;

  tmp = graph->first;
  while (tmp)
    {
      if (!my_strcmp(tmp->name, link))
	{
	  new->prev = tmp;
	  break ;
	}
      tmp = tmp->next[0];
    }
}

bool		push_edge(t_control *graph, char *name, char *link)
{
  t_graph	*tmp;
  t_graph	*new;

  if (!(new = create_elem(link, 1)))
    return (false);
  tmp = graph->first;
  while (tmp)
    {
      if (!my_strcmp(tmp->name, name))
	{
	  if (tmp->next[1])
	    {
	      tmp = tmp->next[1];
	      while (tmp->next[0] != NULL)
		tmp = tmp->next[0];
	      tmp->next[0] = new;
	    }
 	  else
	    tmp->next[1] = new;
	  connect_edge(graph, new, link);
	  break ;
	}
      tmp = tmp->next[0];
    }
  return (true);
}
