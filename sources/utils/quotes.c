/*
** quotes.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Sun Apr 29 12:49:37 2012 tom rossi
** Last update Wed May  2 13:00:42 2012 tom rossi
*/

#include <stdio.h>
#include <token.h>

int	error_q()
{
  printf("Error: non valid quotes\n");
  return (RETURN_ERROR);
}

int	quotes(char *s)
{
  int	i;
  char	c;

  i = 0;
  while (s[i])
    {
      while (s[i] && s[i] != '\"' && s[i] != '\'')
	i++;
      if (!s[i])
	return (RETURN_SUCCESS);
      c = s[i];
      i++;
      while (s[i] && s[i] != '\"' && s[i] != '\'')
        {
          i++;
        }
      if (!s[i] || s[i] != c)
	return (error_q());
      i++;
    }
  return (RETURN_SUCCESS);
}
