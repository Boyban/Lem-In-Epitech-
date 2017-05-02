/*
** last_try.c for get_next_line in /home/Swann/CPE_2016_getnextline
**
** Made by Swann Giboureau
** Login   <Swann@epitech.net>
**
** Started on  Wed Jan 11 00:11:23 2017 Swann Giboureau
** Last update Sun Apr 30 19:56:56 2017 Swann
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	my_get_buffer(const int fd)
{
  static int	xread = 0;
  static char	buf[READ_SIZE + 1];
  static int	index_b = 0;
  char		c;

  if (index_b == xread)
    {
      if ((xread = read(fd, buf, READ_SIZE)) < 1)
	return (0);
      buf[xread] = '\0';
      index_b = 0;
    }
  c = buf[index_b++];
  return (c);
}

char	*get_next_line(const int fd)
{
  int		index;
  char		*read_line;
  char		c;

  index = 0;
  if ((c = my_get_buffer(fd)) == 0)
    return (NULL);
  if (!(read_line = malloc(LINE)))
    return (NULL);
  while (c != '\n' && c != '\0')
    {
      read_line[index++] = c;
      if ((c = my_get_buffer(fd)) == 0)
	{
	  read_line[index] = '\0';
	  return (read_line);
	}
    }
  read_line[index] = '\0';
  return (read_line);
}
