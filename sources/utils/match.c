/*
** match.c for match in /u/all/rossi_t/rendu/piscine/match-nmatch
**
** Made by tom rossi
** Login   <rossi_t@epitech.net>
**
** Started on  Tue Oct 11 21:48:38 2011 tom rossi
** Last update Fri Dec 23 15:06:32 2011 tom rossi
*/

#include "str.h"
int     retmatch(char a, char b);

int	boucle_1(char *s2, int a)
{
  while (s2[a] == '*')
    a = a + 1;
  return (a);
}

int      boucle_2(char *s1, char *s2, int a, int i)
{
  while (s1[i] && s2[a] && (s1[i] != s2[a]))
    {
      if (s1[i] == '\0')
 	return (i);
      i = i + 1;
    }
  return (i);
}

void	plus(int *a, int *b, int *c)
{
  *a += 1;
  *b += 1;
  *c += 1;
}

int	my_match(char *s1, char *s2, int i, int a)
{
  int z;

  z = 0;
  while (s2[a])
    {
      while ((s1[i] == s2[a]) || (s2[a] == '*'))
	{
	  if ((s1[i] == '\0' && s2[a] == '\0') || (s2[0] == '*' && s2[1] == '\0'))
	    return (1);
	  if (s2[a] == '*')
	    {
	      z = 1;
	      a = boucle_1(s2, a);
	      i = boucle_2(s1, s2, a, i);
	    }
	  if (s1[i] != s2[a])
	    return (retmatch(s2[a], s2[a - 1]));
	  plus(&a, &z, &i);
	}
      a = a - z;
      if ((s1[i] != s2[a] && s2[a] != '*') || (s2[a] == '\0'))
	return (0);
    }
  return (0);
}

int	match(char *s1, char *s2)
{
  if (!my_strlen(s1) && !my_strlen(s2))
    return (1);
  return (my_match(s1, s2, 0, 0));
}
