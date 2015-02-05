/*
** mod_hist.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/sources/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Wed May  9 22:34:41 2012 maxime lespagnol
** Last update Thu May 17 10:32:58 2012 alexis letexier
*/

#include	<stdlib.h>
#include	<hist.h>
#include	<str.h>
#include	<lib.h>

void	suppr_hist(t_hist *tmp)
{
  t_hist	*prev;

  prev = tmp->prev;
  if (prev != NULL)
    {
      if (tmp != NULL)
	{
	  xfree(tmp->str);
	  xfree(tmp->copy);
	  prev->next = tmp->next;
	  if (tmp->next != NULL)
	    tmp->next->prev = prev;
	}
    }
}

void	verif_hist(t_hist *ptr, t_hist **hist, int i)
{
  t_hist	*tmp;
  int		k;

  tmp = *hist;
  k = 0;
  while (tmp != NULL && ptr != NULL && tmp->str != NULL
	 && ptr->str != NULL)
    {
      if (i != k && my_strcmp(tmp->str, ptr->str) == 0)
      	suppr_hist(tmp);
      tmp = tmp->next;
      k++;
    }
}

t_hist	*pass_next(t_hist *ptr)
{
  t_hist	*next;
  t_hist	*prev;

  if (ptr != NULL)
    {
      next = ptr->next;
      prev = ptr->prev;
      if (prev != NULL)
	prev->next = next;
      if (next != NULL)
	next->prev = prev;
      xfree(ptr->str);
      xfree(ptr->copy);
      xfree(ptr);
    }
  return (next);
}

void	mod_hist(t_hist **hist, t_sh *sh)
{
  t_hist	*ptr;
  int		i;
  int		flag;

  ptr = *hist;
  i = 0;
  flag = 0;
  while (ptr != NULL)
    {
      verif_hist(ptr, hist, i);
      if ((ptr->str = epur_hist(ptr->str)) == NULL)
      	{
      	  ptr = pass_next(ptr);
      	  flag = 1;
      	}
      if (ptr != NULL)
  	ptr = ptr->next;
      i++;
    }
  if (flag == 0)
    sh->hist = add_in_history((*hist)->str, sh->hist);
}
