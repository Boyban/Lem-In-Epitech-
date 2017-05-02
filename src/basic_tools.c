/*
** basic_tools.c for Project-Master in /home/Swann/tek1/CPE_2016_Lemin/src
** 
** Made by Swann
** Login   <Swann@epitech.eu>
** 
** Started on  Fri Apr 28 19:12:46 2017 Swann
** Last update Sun Apr 30 22:32:33 2017 Swann
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
  my_putchar('\n');
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  if (!s1 || !s2)
    return (1);
  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    ++i;
  return (s1[i] - s2[i]);
}

void	my_put_nbr(int nb)
{
  int	div;

  div = 1;
  if (nb < 0)
    {
      nb *= -1;
      my_putchar('-');
    }
  while (nb / div > 9)
    div *= 10;
  while (div >= 1)
    {
      my_putchar(nb / div % 10 + '0');
      div /= 10;
    }
}
