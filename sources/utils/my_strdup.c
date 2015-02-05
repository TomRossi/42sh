/*
** my_strdup.c for sh in /home/rossi_t//random/projets/42sh/sources/utils
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Tue May  1 09:28:29 2012 tom rossi
** Last update Wed May  2 15:29:53 2012 tom rossi
*/

#include <stdlib.h>
#include <str.h>

char	*my_strdup(char *s)
{
  char	*out;
  int	i;

  i = 0;
  if (!s)
    {
      out = malloc(sizeof(*s));
      out[0] = '\0';
      return (out);
    }
  out = malloc(sizeof(*s) * (my_strlen(s) + 1));
  if (!out)
    return (NULL);
  while (s[i])
    {
      out[i] = s[i];
      i++;
    }
  out[i] = '\0';
  return (out);
}
