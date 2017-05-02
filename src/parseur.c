/*
** parseur.c for Project-Master in /home/Swann/tek1/CPE_2016_Lemin/src
**
** Made by Swann
** Login   <Swann@epitech.eu>
**
** Started on  Fri Apr 28 12:19:25 2017 Swann
** Last update Sun Apr 30 22:30:13 2017 Swann
*/

#include <stdlib.h>
#include <stdbool.h>
#include "parseur.h"
#include "get_next_line.h"

static bool	push_display(char *str, t_control *graph, int nb)
{
  char	*buffer;

  my_putstr(str);
  if (!(buffer = get_next_line(0))
      || !check_form(buffer) || !push_vertex(graph, get_arg1(buffer, ' '), nb))
    return (false);
  my_putstr_nb(buffer, '#');
  return (true);
}

static bool	push_room(t_control *graph, char *buffer)
{
  if (!check_form(buffer))
    return (false);
  my_putstr_nb(buffer, '#');
  if (!push_vertex(graph, get_arg1(buffer, ' '), 0))
      return (false);
  return (true);
}

static bool	push_connection(t_control *graph, char *buffer)
{
  char	*prem_arg;
  char	*second_arg;
  static int	nb;

  if (nb == 0 && ++nb)
    my_putstr(TUNNELS);
  if (!(prem_arg = get_arg1(buffer, '-'))
      || !(second_arg = get_arg2(buffer, '-'))
      || !push_edge(graph, prem_arg, second_arg)
      || !push_edge(graph, second_arg, prem_arg))
    return (false);
  my_putstr(buffer);
  return (true);
}

int	check_line(char *buffer, t_control *graph)
{
  int	nb;

  nb = 0;
  if ((!my_strcmp(buffer, ENTRY) && ++nb)
     || (!my_strcmp(buffer, EXIT) && --nb))
   {
     if ((nb == 1 && !push_display(ENTRY, graph, nb))
	 || (nb == -1 && !push_display(EXIT, graph, nb)))
       return (0);
   }
  else if ((nb_arg(buffer, ' ') == 3 && is_num(buffer)
	    && !push_room(graph, buffer)))
    return (0);
  else if (nb_arg(buffer, '-') == 2
	   && !push_connection(graph, buffer))
    return (0);
  else
    return (1);
  return (2);
}

t_control	*parseur()
{
  int		nb_ant;
  t_control	*graph;
  char		*buffer;
  char		*entry;
  t_graph	*tmp;

  if (!(graph = create_graph()))
    return (NULL);
  nb_ant = 0;
  while ((buffer = get_next_line(0)))
    {
      if (nb_ant == 0 && is_num(buffer) && (nb_ant = my_getnbr(buffer))
	  && nb_ant > 0)
	display_ant(nb_ant);
      else if (!check_line(buffer, graph) || nb_ant <= 0)
	return (NULL);
      free(buffer);
    }
  if (!(tmp = graph->first))
    return (NULL);
  entry = tmp->name;
  if (!(suit_parseur(nb_ant, graph, entry)))
    return (NULL);
  return (graph);
}
