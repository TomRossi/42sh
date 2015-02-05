/*
** manage_next_word.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/sources/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Thu May 10 18:08:20 2012 maxime lespagnol
** Last update Sun May 13 17:54:58 2012 maxime lespagnol
*/

#include	<stdlib.h>
#include	<term_man.h>
#include	<str.h>

void	manage_right_ctrl(int i, char *str, t_term *ptr)
{
  while (i < (my_strlen(str) - 1) && str[i] != ' ')
    {
      move_right(ptr);
      i--;
    }
}

void	manage_left_ctrl(int i, char *str, t_term *ptr)
{
  while (i > 0 && str[i] != ' ')
    {
      move_left(ptr);
      i--;
    }
}

void	manage_next_word(t_term *ptr)
{
  int	i;

  i = ptr->pos;
  if (ptr->str != NULL)
    {
      if (ptr->flag == CTRL_LEFT)
	manage_left_ctrl(ptr->pos, ptr->str, ptr);
      if (ptr->flag == CTRL_RIGHT)
	manage_right_ctrl(ptr->pos, ptr->str, ptr);
    }
}
