/*
** xfunc.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/lib
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Tue May  1 03:33:39 2012 maxime lespagnol
** Last update Fri May 11 22:15:09 2012 maxime lespagnol
*/

#include	<stdlib.h>

void	xfree(void *ptr)
{
  if (ptr != NULL)
    free(ptr);
}

void	xfree_tab(char **ptr)
{
  int	i;

  if (ptr != NULL)
    {
      i = 0;
      while (ptr[i] != NULL)
	free(ptr[i++]);
      free(ptr);
    }
}
