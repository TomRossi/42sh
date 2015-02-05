/*
** my_strncmp.c for my_strncmp in /home/quemen_g//Projects/Max/sources/termcap/autocompletion
**
** Made by guillaume quemener
** Login   <quemen_g@epitech.net>
**
** Started on  Mon May 14 12:54:50 2012 guillaume quemener
** Last update Wed May 16 18:53:01 2012 maxime lespagnol
*/

#include	<stdlib.h>

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  if (s1 != NULL && s2 != NULL)
    {
      while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
	  if (s1[i] != s2[i])
	    return (1);
	  i++;
	}
      return (0);
    }
  return (1);
}
