/*
** my_getstr.c for calc in /home/rossi_t//random/colle/colle2/SVN
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Thu Apr 26 23:16:51 2012 tom rossi
** Last update Sat May 19 11:01:09 2012 tom rossi
*/

#include <stdlib.h>
#include <str.h>

int	get_len(int nb)
{
  int	len;

  len = 0;
  while (nb)
    {
      len += 1;
      nb = nb / 10;
    }
  return (len);
}

void	fill_str(char *str, int nb, int i)
{
  int	len;
  int	p;

  len = get_len(nb) - 1;
  while (len)
    {
      p = my_pow(10, len);
      str[i++] = nb / p + '0';
      nb -= p * (nb / p);
      len -= 1;
    }
  str[i++] = nb + '0';
  str[i] = '\0';
}

char	*my_getstr(int nb)
{
  char	*new;
  int	len;

  if (!nb)
    return (my_strdup("0"));
  len = get_len(nb);
  if (nb < 0)
    len += 1;
  new = malloc(sizeof(*new) * (len + 1));
  if (!new)
    return (NULL);
  len = 0;
  if (nb < 0)
    {
      new[0] = '-';
      len += 1;
      nb = -nb;
    }
  fill_str(new, nb, len);
  return (new);
}
