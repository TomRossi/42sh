/*
** error_manage.c for error_manage in /home/letexi_a//Documents/Tek1/Projets/42sh
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Tue Mar 27 15:36:29 2012 alexis letexier
** Last update Wed May 16 17:13:26 2012 alexis letexier
*/

#include	<alias.h>
#include	<env.h>

int	verif_unalias(char **tab_a)
{
  int	n;

  n = 0;
  while (tab_a[n] != NULL)
    n++;
  if (n >= 2 && my_strcmp(tab_a[0], "unalias") == 0)
    return (0);
  else
    {
      my_putfd("unalias: Too few arguments.\n", 2);
      return (-1);
    }
}

int	error_alias(char **tab_a)
{
  if (tab_a != NULL)
    {
      if (verif_add_alias(tab_a) == -1)
	{
	  if (verif_unalias(tab_a) == -1)
	    return (-1);
	}
    }
  return (0);
}
