/*
** my_getnbr.c for my_getnbr in /home/Swann789/CPool_Day04
**
** Made by Swann Giboureau
** Login   <Swann789@epitech.net>
**
** Started on  Wed Oct 12 12:25:55 2016 Swann Giboureau
** Last update Fri Apr 28 20:50:12 2017 Swann
*/

int	my_getnbr(char *str)
{
  int	i;
  int	sign;
  int	nb;

  i = 0;
  sign = 1;
  nb = 0;
  while (str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
	sign = sign * (-1);
      i = i + 1;
    }
   while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
     {
       if (nb > 214748364)
	 return (0);
       nb = nb * 10 - '0';
       nb = nb + str[i];
       i = i + 1;
     }
   if (sign == -1)
     nb = nb * (-1);
   return (nb);
}
