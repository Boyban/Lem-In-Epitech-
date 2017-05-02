/*
** check_arg.c for Project-Master in /home/Swann/tek1/CPE_2016_Lemin/src
**
** Made by Swann
** Login   <Swann@epitech.eu>
**
** Started on  Fri Apr 28 18:17:05 2017 Swann
** Last update Sun Apr 30 20:45:13 2017 Swann
*/

#include <stdbool.h>
#include <stdlib.h>

int	nb_arg(char *str, char c)
{
  int	index;
  int	count;

  index = 0;
  count = 0;
  while (str[index])
    {
      if ((str[index] == c || str[index + 1] == '\0') && str[index])
	++count;
      ++index;
    }
  return (count);
}

bool	is_num(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
	return (false);
      ++i;
    }
  return (true);
}

bool	is_connection(char *str)
{
  return (str[1] == '-' ? 1 : 0);
}

char	*get_arg1(char *buffer, char c)
{
  char	*str;
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (buffer[count] && buffer[count] != c)
    ++count;
  if (!(str = malloc(sizeof(char) * (count + 1))))
    return (NULL);
  while (buffer[i] != c)
    {
      str[i] = buffer[i];
      ++i;
    }
  str[i] = '\0';
  return (str);
}

char	*get_arg2(char *buffer, char c)
{
  char	*str;
  int	i;
  int	count;
  int	tmp;

  count = 0;
  i = 0;
  while (buffer[i] != c)
    ++i;
  tmp = ++i;
  while (buffer[i++])
    ++count;
  if (!(str = malloc(sizeof(char) * (count + 1))))
    return (NULL);
  count = 0;
  while (buffer[tmp])
    str[count++] = buffer[tmp++];
  str[count] = '\0';
  return (str);
}
