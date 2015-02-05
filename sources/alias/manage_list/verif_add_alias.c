/*
** verif_add_alias.c for verif_add_alias in /home/letexi_a//Documents/Tek1/Projets/42sh
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Thu Apr  5 10:00:33 2012 alexis letexier
** Last update Wed May 16 16:55:04 2012 alexis letexier
*/

#include	<alias.h>

int	verif_tcsh_alias(char **tab_a, int n)
{
  while (tab_a[n] != NULL)
    n++;
  if (n >= 3)
    {
      if (my_strcmp(tab_a[0], "alias") == 0)
	return (0);
      else
	return (-1);
    }
  else if ((n == 1 && my_strcmp(tab_a[0], "alias") == 0)|| n == 2)
    return (0);
  else
    return (-1);
}

int     verif_add_alias(char **tab_a)
{
  int   n;

  n = 0;
  if (tab_a != NULL)
    {
      if (tab_a[n] != NULL && my_strcmp(tab_a[n], "alias") == 0)
        {
          if (verif_tcsh_alias(tab_a, n) == -1)
	    return (-1);
        }
      else
	return (-1);
    }
  return (0);
}
