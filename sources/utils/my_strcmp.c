/*
** my_strcmp.c for my_strcmp in /u/all/rossi_t/rendu/piscine/Jour_06
**
** Made by tom rossi
** Login   <rossi_t@epitech.net>
**
** Started on  Mon Oct 10 09:28:05 2011 tom rossi
** Last update Fri May 18 13:59:37 2012 tom rossi
*/

#include	<stdlib.h>
#include	<str.h>

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  if (s1 != NULL && s2 != NULL)
    {
      if (my_strlen(s1) == my_strlen(s2))
	{
	  i = 0;
	  while (s1[i] != '\0')
	    {
	      if ((s1[i] - s2[i]) != 0)
		return (1);
	      i++;
	    }
	  return (0);
	}
      return (1);
    }
  return (1);
}
