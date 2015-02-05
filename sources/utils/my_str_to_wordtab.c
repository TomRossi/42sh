/*
** my_str_to_wordtab.c for my_str_to_wordtab in /u/all/rossi_t/rendu/piscine/Jour_08/ex_01
**
** Made by tom rossi
** Login   <rossi_t@epitech.net>
**
** Started on  Wed Oct 12 14:44:13 2011 tom rossi
** Last update Sat May 19 11:02:58 2012 tom rossi
*/

#include <stdlib.h>
#include <str.h>

int     is_sep(char a, char *sep)
{
  int	i;

  i = 0;
  while (sep[i])
    {
      if (a == sep[i])
	return (1);
      i++;
    }
  return (0);
}

int	len(char *str, int i, char *sep)
{
  int x;

  x = 0;
  while (str[i] && !is_sep(str[i], sep))
    {
      i = i + 1;
      x = x + 1;
    }
  return (x);
}

char	*wcopy(char *str, char *str_out, int i, char *sep)
{
  int	a;

  a = 0;
  str_out = malloc(sizeof(*str_out) * (len(str, i, sep) + 1));
  if (!str_out)
    return (NULL);
  while (str[i] && !is_sep(str[i], sep))
    str_out[a++] = str[i++];
  str_out[a] = '\0';
  return (str_out);
}

int	words(char *str, char *sep)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (str[i] && is_sep(str[i], sep))
    i++;
  if (!str[i])
    return (0);
  while (str[i])
    {
      if (is_sep(str[i], sep) && str[i + 1] && !(is_sep(str[i + 1], sep)))
	count++;
      i++;
    }
  return (count + 1);
}

char	**my_str_to_wordtab(char *str, char *sep)
{
  int	i;
  int	x;
  char	**tab;

  if (!(tab = malloc(sizeof(*tab) * (words(str, sep) + 1)))
      || !(words(str, sep)))
    return (NULL);
  x = 0;
  i = 0;
  while (str[i] && is_sep(str[i], sep))
    i++;
  while (str[i])
    {
      if (!is_sep(str[i], sep))
	{
	  if (!(tab[x] = wcopy(str, tab[x], i, sep)))
	    return (NULL);
	  x++;
	  while (str[i + 1] && !is_sep(str[i], sep))
	    i++;
	}
      i = i + 1;
    }
  tab[x] = NULL;
  return (tab);
}
