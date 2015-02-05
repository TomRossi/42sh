/*
** show_hist.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/Termcaps/hist
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Tue Mar 27 18:10:48 2012 maxime lespagnol
** Last update Thu Apr  5 10:56:13 2012 tom rossi
*/

#include	<stdlib.h>
#include	<str.h>
#include	<hist.h>

void	show_hist(t_hist **hist)
{
  t_hist	*ptr;

  ptr = *hist;
  my_putstr("\n--------------------------\nSHOW_HIST ====>\n");
  while (ptr != NULL)
    {
      my_putstr(ptr->str);
      my_putchar('\n');
      ptr = ptr->next;
    }
  my_putstr("END\n----------------------\n");
}
