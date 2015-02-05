/*
** aff_copy.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/sources/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Fri May  4 16:16:04 2012 maxime lespagnol
** Last update Wed May  9 21:43:06 2012 maxime lespagnol
*/

#include	<stdlib.h>
#include	<term.h>
#include	<str.h>
#include	<term_man.h>

void	aff_copy(t_term *ptr)
{
  if (ptr->flag == COPY_W)
    {
      go_begin(ptr);
      my_putstr(tgetstr("cd", NULL));
      my_putstr(ptr->str);
      ptr->pos = my_strlen(ptr->str);
      go_begin(ptr);
    }
  else
    my_putstr(tgetstr("cd", NULL));
}

void	add_into_struct(char *cpy, t_term *ptr)
{
  if (cpy != NULL && cpy[0] != '\0')
    {
      xfree(ptr->copy);
      ptr->copy = my_strdup(cpy);
    }
}
