/*
** tools_finish.c for  in /home/yohan/CPE_2016_Lemin/src
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Sun Apr 30 16:08:26 2017 Yohan
** Last update Sun Apr 30 22:28:16 2017 Swann
*/

#include <stdbool.h>
#include <unistd.h>
#include "parseur.h"

bool	suit_parseur(int nb_ant, t_control *graph, char *entry)
{
  t_graph	*tmp;
  char		*exit;
  t_path	path;

  if (!(tmp = graph->last))
    return (false);
  exit = tmp->name;
  if (my_astar(graph, exit) != 0)
    return (false);
  if (!(path = take_path(graph, entry)))
    return (false);
  finish(path, nb_ant);
  return (true);
}

void	my_putstr_backn(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\n' && str[i] != '\0')
    {
      write(1, &str[i], 1);
      ++i;
    }
}

int	nb_space(char *str)
{
  int	count;

  count = 0;
  while (*str)
    {
      if (*str == ' ')
	++count;
      ++str;
    }
  return (count);
}

bool	check_form(char *str)
{
  if (nb_arg(str, ' ') < 3 || nb_space(str) < 2)
    return (false);
  while (*str != ' ' && *str)
    ++str;
  ++str;
  while (*str != ' ' )
    {
      if (*str < '0' || *str > '9')
	return (false);
      ++str;
    }
  ++str;
  while (*str != ' ' && *str)
    {
      if (*str < '0' || *str > '9')
	return (false);
      ++str;
    }
  return (true);
}
