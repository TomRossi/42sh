/*
** manage_hist.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/sources/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Wed May  9 21:43:50 2012 maxime lespagnol
** Last update Wed May  9 22:31:06 2012 maxime lespagnol
*/

#include	<stdlib.h>
#include	<term.h>
#include	<term_man.h>
#include	<hist.h>
#include	<str.h>

int	move_up(t_term *term, t_hist **hist, t_hist *ptr)
{
  if (term->flag == UP)
    {
      while (ptr != NULL && ptr->select != 1)
	ptr = ptr->next;
      if (ptr != NULL)
	{
	  ptr->select = 0;
	  term->flag_cr = 0;
	  xfree(term->str);
	  term->str = my_strdup(ptr->str);
	  if (ptr->next != NULL)
	    ptr = ptr->next;
	  ptr->select = 1;
	}
    }
  return (0);
}

int	move_down(t_term *term, t_hist **hist, t_hist *ptr)
{
  if (term->flag == DOWN)
    {
      if (ptr != NULL)
        {
	  ptr->select = 0;
          term->flag_cr = 0;
          xfree(term->str);
          if (ptr->prev != NULL)
	    {
	      ptr = ptr->prev;
	      term->str = my_strdup(ptr->str);
	    }
	  else
	    {
	      term->flag_cr = 1;
	      term->str = my_strdup(term->str_cr);
	    }
	  ptr->select = 1;
        }
    }
  return (0);
}

int	manage_up_or_down(t_term *term, t_hist **hist)
{
  t_hist	*ptr;

  ptr = *hist;
  while (ptr != NULL && ptr->select != 1)
    ptr = ptr->next;
  if (term->flag == DOWN)
    move_down(term, hist, ptr);
  if (term->flag == UP)
    move_up(term, hist, ptr);
  go_begin(term);
  my_putstr(tgetstr("cd", NULL));
  my_putstr(term->str);
  term->pos = my_strlen(term->str);
  return (0);
}

int	manage_hist(t_term *term, t_hist **hist)
{
  if (*hist != NULL)
    {
      if (term->flag == UP || term->flag == DOWN)
	{
	  if (manage_up_or_down(term, hist) == -1)
	    return (-1);
	}
      else if (term->flag_cr == 1 && term->flag != DOWN && term->flag != UP)
	{
	  xfree(term->str_cr);
	  if ((term->str_cr = my_strdup(term->str)) == NULL)
	    return (-1);
	}
    }
  return (0);
}
