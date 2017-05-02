/*
** structure.h for  in /home/yohan/liste_chaine/train/include
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Tue Apr 11 17:14:39 2017 Yohan
** Last update Sun Apr 30 20:47:25 2017 Swann
*/

#ifndef ASTAR_H_
# define ASTAR_H_
# include "parseur.h"

typedef	struct		s_star
{
  t_graph		*next;
  struct s_star		*last;
}			t_star;

typedef struct		s_way
{
  char			*name;
  struct s_way		*next;
}			t_way;

typedef struct		s_ant
{
  char			*path;
  int			index;
  struct s_ant		*next;
}			t_ant;

typedef t_star*		t_alg;
typedef t_way*		t_path;

t_path		take_path(t_control*, char*);
int		my_astar(t_control *, char *);
void		finish(t_path, int);
void		aff_ant(int, t_path);
void		aff_list(t_ant *);
t_ant		*add_path_start(t_ant *, char *, int);
void		my_putstr_backn(char*);

#endif /* !ASTAR_H_ */
