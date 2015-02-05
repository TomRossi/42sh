/*
** manage_clear_beg_end.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Wed May  2 05:34:42 2012 maxime lespagnol
** Last update Fri May 18 11:29:17 2012 maxime lespagnol
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<str.h>
#include	<term.h>
#include	<lib.h>
#include	<term_man.h>

void	make_clear(t_term *ptr)
{
  int	i;
  int	n;

  i = my_strlen(ptr->str);
  my_putstr(tgetstr("cl", NULL));
  my_putstr(ptr->prompt);
  my_putstr(ptr->str);
  n = ((my_strlen(ptr->str) + ptr->s_pr) / ptr->col);
  while (n > (ptr->pos / ptr->col))
    {
      my_putstr(tgetstr("up", NULL));
      n = n - ptr->col;
    }
  n = ptr->pos + ptr->s_pr;
  while (n > ptr->col)
    n = n - ptr->col;
  my_putstr(tparm(tgetstr("ch", NULL), n));
}

void	go_begin(t_term *ptr)
{
  int	n;

  n = ((ptr->s_pr + ptr->pos - 1) / ptr->col);
  while (n > 0)
    {
      my_putstr(tgetstr("up", NULL));
      n--;
    }
  my_putstr(tparm(tgetstr("ch", NULL), ptr->s_pr));
  ptr->pos = 0;
}

void	go_end(t_term *ptr)
{
  int   n;

  n = ptr->pos + ptr->s_pr;
  while (n > ptr->col)
    {
      my_putstr(tgetstr("up", NULL));
      n = n - ptr->col;
    }
  n = ((my_strlen(ptr->str) + ptr->s_pr) / ptr->col);
  while (n > 0)
    {
      my_putstr(tgetstr("do", NULL));
      n--;
    }
  n = my_strlen(ptr->str) + ptr->s_pr;
  while (n > ptr->col)
    n = n - ptr->col;
  ptr->pos = my_strlen(ptr->str);
  my_putstr(tparm(tgetstr("ch", NULL), n));
}

void	manage_clear_beg_end(t_term *ptr)
{
  if (ptr->flag == CLEAR)
    make_clear(ptr);
  if (ptr->flag == BEGIN)
    go_begin(ptr);
  if (ptr->flag == END)
    go_end(ptr);
}
