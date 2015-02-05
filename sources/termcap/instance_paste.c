/*
** instance_paste.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/sources/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Fri May  4 16:23:18 2012 maxime lespagnol
** Last update Wed May  9 21:42:13 2012 maxime lespagnol
*/

#include	<stdlib.h>
#include	<str.h>
#include	<term.h>
#include	<term_man.h>

int	add_paste(t_term *ptr, int i, int k, int j)
{
  char	*tmp;

  tmp = NULL;
  if (ptr->copy != NULL)
    {
      k = my_strlen(ptr->str) + my_strlen(ptr->copy);
      if ((tmp = malloc(sizeof(*tmp) * (k + 1))) == NULL)
	return (0);
      k = 0;
      while (ptr->str != NULL && ptr->str[i] != '\0' && i < ptr->pos)
	tmp[k++] = ptr->str[i++];
      while (ptr->copy != NULL && ptr->copy[j] != '\0')
	tmp[k++] = ptr->copy[j++];
      while (ptr->str != NULL && ptr->str[i] != '\0')
	tmp[k++] = ptr->str[i++];
      tmp[k] = '\0';
      xfree(ptr->str);
      ptr->str = my_strdup(tmp);
      xfree(tmp);
    }
  return (0);
}

void	aff_paste(t_term *ptr)
{
  int   dist;
  int   n;

  my_putstr(tgetstr("cd", NULL));
  my_putstr_spe(ptr->str, ptr, ptr->pos);
  ptr->pos = ptr->pos + my_strlen(ptr->copy);
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

void	instance_paste(t_term *ptr)
{
  add_paste(ptr, 0, 0, 0);
  aff_paste(ptr);
}
