/*
** move_aff.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Wed May  2 00:49:27 2012 maxime lespagnol
** Last update Sun May 13 17:38:17 2012 maxime lespagnol
*/

#include	<term.h>
#include	<stdlib.h>
#include	<str.h>
#include	<term_man.h>

void	move_left(t_term *ptr)
{
  int	n;
  int	flag;

  n = 1;
  flag = 0;
  while (n <= ((ptr->s_pr + my_strlen(ptr->str)) / ptr->col))
    {
      if ((ptr->pos + ptr->s_pr) == (n * ptr->col))
	flag = 1;
      n++;
    }
  ptr->pos = ptr->pos - 1;
  if (ptr->pos < 0)
    ptr->pos = 0;
  else
    {
      if (flag == 0)
	my_putchar('\b');
      else
	{
	  my_putstr(tgetstr("up", NULL));
	  my_putstr(tparm(tgetstr("ch", NULL), ptr->col));
	}
    }
}

void    move_right(t_term *ptr)
{
  int   n;
  int   flag;

  n = 1;
  flag = 0;
  while (n <= ((ptr->s_pr + my_strlen(ptr->str)) / ptr->col))
    {
      if ((ptr->pos + ptr->s_pr) == (n * ptr->col - 1))
        flag = 1;
      n++;
    }
  ptr->pos = ptr->pos + 1;
  if (ptr->pos > my_strlen(ptr->str))
    ptr->pos = my_strlen(ptr->str);
  else
    {
      if (flag == 0)
	my_putchar(ptr->str[ptr->pos - 1]);
      else
        {
          my_putstr(tgetstr("do", NULL));
          my_putstr(tparm(tgetstr("ch", NULL), 0));
        }
    }
}

void	move_left_or_right(t_term *ptr)
{
  if (ptr->flag == LEFT_T)
    move_left(ptr);
  if (ptr->flag == RIGHT_T)
    move_right(ptr);
}
