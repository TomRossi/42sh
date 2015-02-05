/*
** aff_history.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/sources/history
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Sat May 12 16:00:50 2012 maxime lespagnol
** Last update Wed May 16 16:11:23 2012 maxime lespagnol
*/

#include	<stdlib.h>
#include        <sys/types.h>
#include        <sys/stat.h>
#include        <fcntl.h>
#include	<str.h>
#include	<env.h>

void	aff_just_hist(char **hist)
{
  int	i;

  i = 0;
  while (hist != NULL && hist[i] != NULL)
    {
      my_putchar('\t');
      my_putnbr(i);
      my_putchar('\t');
      my_putstr(hist[i]);
      i++;
      my_putchar('\n');
    }
}

int	aff_history(char **opt, int fd, t_sh *sh)
{
  int	k;

  k = 1;
  if (sh != NULL && opt != NULL && opt[k] == NULL)
    aff_just_hist(sh->hist);
  while (sh != NULL && opt != NULL && opt[k] != '\0')
    {
      if (opt[k] != NULL && my_strcmp(opt[k], "-c") == 0)
	{
	  xfree_tab(sh->hist);
	  sh->hist = NULL;
	}
      k++;
    }
  return (0);
}
