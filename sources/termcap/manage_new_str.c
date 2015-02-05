/*
** manage_new_str.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/sources/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Thu May 10 17:28:45 2012 maxime lespagnol
** Last update Thu May 10 17:36:53 2012 maxime lespagnol
*/

#include	<stdlib.h>
#include	<str.h>
#include	<hist.h>
#include	<term_man.h>

char	*manage_new_str(t_hist **hist)
{
  t_hist	*ptr;
  char		*ret;

  ptr = *hist;
  ret = NULL;
  if (ptr != NULL)
    if (ptr->flag == ALT_A)
      {
	ret = my_strdup(ptr->str);
	my_putstr(ret);
      }
  return (ret);
}
