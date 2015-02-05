/*
** my_putnbr.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Sat May 12 17:07:01 2012 maxime lespagnol
** Last update Wed May 16 17:02:22 2012 tom rossi
*/

#include	<str.h>

void    my_putnbr(int nb)
{
  int   i;

  if (nb < 0)
    my_putchar('-');
  else if (nb == 0)
    my_putchar(nb);
  else
    nb = nb * -1;
  i = -1;
  while (nb / -i < -9)
    i = i * 10;
  while (nb <= 0 && i < 0)
    {
      my_putchar(nb / i + 48);
      nb = nb % i;
      i = i / 10;
    }
}

int     my_getnbr(char *str)
{
  int	i;
  int   sign;
  int   nbr;

  if (!str || !str[0])
    return (0);
  sign = 1;
  i = 0;
  while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
    {
      if (str[i] == '-')
        sign = sign * (-1);
      i++;
    }
  nbr = 0;
  while (str[i] >= '0' && str[i] <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr - (str[i] - '0');
      i++;
    }
  if ((str[i] > '\0' && str[i] < '0') || str[i] > '9')
    return (0);
  return (nbr * sign * (-1));
}

int	check_val(char *val)
{
  int	k;

  k = 0;
  while (val[k] != '\0')
    {
      if ((val[k] >= '0' && val[k] <= '9') || val[k] == '-')
	k++;
      else
	return (1);
    }
  return (0);
}
