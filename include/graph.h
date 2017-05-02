/*
** graph.h for Lemin in /home/swann/epitech/CPE_2016_Lemin/src
**
** Made by Giboureau
** Login   <swann@epitech.net>
**
** Started on  Tue Apr 18 10:33:10 2017 Giboureau
** Last update Sun Apr 30 15:58:33 2017 Yohan
*/

#include <stdbool.h>

# define NOUSE          __attribute__((unused))

typedef struct		s_graph
{
  char			*name;
  struct s_graph	**next;
  struct s_graph	*prev;
}			t_graph;

typedef struct	s_control
{
  int		length;
  t_graph	*first;
  t_graph	*last;
}		t_control;

bool		push_vertex(t_control *, char *, int);
bool		push_edge(t_control *, char *, char *);
t_graph		*create_elem(char *, int);
t_control	*create_graph();
void		show_graph(t_control *);
