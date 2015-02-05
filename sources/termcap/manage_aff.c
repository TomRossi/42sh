/*
** manage_aff.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Wed May  2 00:33:59 2012 maxime lespagnol
** Last update Wed May 16 13:38:08 2012 maxime lespagnol
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<term.h>
#include	<str.h>
#include	<term_man.h>
#include	<env.h>

void    manage_tab(t_term *ptr, t_env **env_tmp);

void	my_putstr_spe(char *str, t_term *ptr, int i)
{
  int	n;

  while (str[i] != '\0')
    {
      n = ((ptr->s_pr + ptr->pos) / ptr->col);
      if ((n * ptr->col) == (i + ptr->s_pr))
	my_putchar(ptr->str[i - 1]);
      my_putchar(ptr->str[i++]);
    }
}

void	just_aff(t_term *ptr)
{
  int	dist;
  int	n;

  my_putstr(tgetstr("cd", NULL));
  my_putstr_spe(ptr->str, ptr, ptr->pos);
  ptr->pos = ptr->pos + my_strlen(ptr->buff);
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

void	manage_aff(t_term *ptr, t_env **env)
{
  if (ptr->flag == NOTH)
    just_aff(ptr);
  if (ptr->flag == STR_ENTER)
    {
      just_aff(ptr);
      ptr->flag = ENTER;
    }
  if (ptr->flag == LEFT_T || ptr->flag == RIGHT_T)
    move_left_or_right(ptr);
  if (ptr->flag == DELETE || ptr->flag == BACKSPACE)
    delete_aff(ptr);
  if (ptr->flag == COPY || ptr->flag == PASTE || ptr->flag == COPY_W)
    manage_copy_and_paste(ptr);
  if (ptr->flag == BEGIN || ptr->flag == END || ptr->flag == CLEAR)
    manage_clear_beg_end(ptr);
  if (ptr->flag == TAB)
    manage_tab(ptr, env);
  if (ptr->flag == CTRL_LEFT || ptr->flag == CTRL_RIGHT)
    manage_next_word(ptr);
}
