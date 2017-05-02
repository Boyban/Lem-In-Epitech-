/*
** parseur.h for Project-Master in /home/Swann/tek1/CPE_2016_Lemin/src
**
** Made by Swann
** Login   <Swann@epitech.eu>
**
** Started on  Fri Apr 28 14:47:12 2017 Swann
** Last update Sun Apr 30 22:30:56 2017 Swann
*/

#ifndef PARSEUR_H_
# define PARSEUR_H_
# include "graph.h"
# include "stdbool.h"
# include "astar.h"
# include "basic.h"
# define ENTRY "##start"
# define EXIT "##end"
# define ANT "#number_of_ants"
# define ROOMS "#rooms"
# define TUNNELS "#tunnels"

/* check string */
int	nb_arg(char *, char);
bool	is_num(char *);
bool	check_form(char *);
bool	is_connection(char *);
int	check_line(char *, t_control *);

/* handle string */
char	*get_arg1(char *, char);
char	*get_arg2(char *, char);

/* display */
void	display_ant(int);

/* Verification's suit before finish */
bool		suit_parseur(int nb_ant, t_control *graph, char *entry);
t_control	*parseur();

#endif /* !PARSEUR_H_ */
