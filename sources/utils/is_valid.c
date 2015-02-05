/*
** is_valid.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Wed Mar 28 13:06:33 2012 tom rossi
** Last update Wed Apr  4 10:29:48 2012 tom rossi
*/

#include <token.h>

int	is_char_valid(char c, char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (s[i] == c)
	return (TRUE);
      i++;
    }
  return (FALSE);
}

int	is_str_valid(char *c, char *s)
{
  int	i;

  i = 0;
  while (c[i])
    {
      if (c[i] && is_char_valid(c[i], s) == FALSE)
	return (FALSE);
      i++;
    }
  return (TRUE);
}

int    skip_char(char *s, char *ref, int *i)
{
  int   x;

  x = *i;
  while (s[x] && is_char_valid(s[x], ref) == TRUE)
    x++;
  if (x == *i)
    return (FALSE);
  *i = x;
  return (TRUE);
}

void    wait_for(char *s, char *ref, int *i)
{
  int   x;

  x = *i;
  while (s[x] && is_char_valid(s[x], ref) == FALSE)
    x++;
  *i = x;
}
