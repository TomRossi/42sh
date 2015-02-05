/*
** delete_aff.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Wed May  2 03:10:30 2012 maxime lespagnol
** Last update Mon May 14 15:28:27 2012 maxime lespagnol
*/

#include        <term.h>
#include        <stdlib.h>
#include	<str.h>
#include        <term_man.h>

void    delete_this(t_term *ptr)
{
  int   n;
  int   dist;
  int	i;

  if (ptr->str != NULL)
    {
      i = ptr->pos;
      my_putstr(tgetstr("cd", NULL));
      while (ptr->str[i] != '\0')
        my_putchar(ptr->str[i++]);
      dist = my_strlen(ptr->str) + ptr->s_pr;
      while (dist > ptr->col)
        {
          dist = dist - ptr->col;
          my_putstr(tgetstr("up", NULL));
        }
      n = ptr->pos + ptr->s_pr;
      while (n > ptr->col)
        {
          n = n - ptr->col;
          my_putstr(tgetstr("do", NULL));
        }
      my_putstr(tparm(tgetstr("ch", NULL), n));
    }
}

void	aff_backspace(t_term *ptr)
{
  int	n;

  n = 1;
  while ((n * ptr->col) <= (ptr->s_pr + my_strlen(ptr->str)))
    n++;
  while (n > 0)
    {
      if ((ptr->pos + ptr->s_pr + 1) == (n * ptr->col))
	{
	  my_putstr(tparm(tgetstr("ch", NULL), (ptr->col - 1)));
	  my_putstr(tgetstr("up", NULL));
	}
      n--;
    }
}

void    backspace_man(t_term *ptr)
{
  int	i;

  move_left(ptr);
  if (ptr->str != NULL)
    {
      i = ptr->pos;
      my_putstr(tgetstr("sc", NULL));
      my_putstr(tgetstr("cd", NULL));
      while (ptr->str[i] != '\0')
        my_putchar(ptr->str[i++]);
      my_putstr(tgetstr("rc", NULL));
      if (ptr->str[ptr->pos] == '\0')
	aff_backspace(ptr);
    }
}

void    delete_aff(t_term *ptr)
{
  if (ptr->flag == DELETE)
    delete_this(ptr);
  if (ptr->flag == BACKSPACE)
    backspace_man(ptr);
}
