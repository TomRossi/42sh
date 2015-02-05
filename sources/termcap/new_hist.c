/*
** manage_term.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Thu Apr 26 18:29:09 2012 maxime lespagnol
** Last update Wed May 16 16:49:25 2012 maxime lespagnol
*/

#include	<sys/ioctl.h>
#include	<stdlib.h>
#include	<term.h>
#include        <lib.h>
#include        <hist.h>
#include        <term_man.h>
#include	<str.h>
#include        <env.h>

void    manage_aff(t_term *ptr, t_env **env);
t_hist  *create_new_hist(t_term *term, t_hist **ptr, char *cpy, t_sh *sh);

int	full_term_info(t_term *ptr)
{
  struct        winsize w;

  if ((ioctl(0, TIOCGWINSZ, &w)) < 0)
    return (-1);
  ptr->col = w.ws_col;
  ptr->row = w.ws_row;
  return (0);
}

void	free_term(t_term *term)
{
  if (term != NULL)
    {
      xfree(term->copy);
      xfree(term->prompt);
      xfree(term->str);
      xfree(term->buff);
      xfree(term);
    }
}

t_term	*for_begin(t_env **env, char *prompt, t_hist **ptr)
{
  t_term	*term;
  char		*cpy;

  cpy = manage_new_copy(ptr);
  if ((term = create_term_man(NULL, prompt, cpy, ptr)) == NULL)
    return (NULL);
  if ((term_mod(env)) == -1)
    return (NULL);
  return (term);
}

t_hist	*for_end(t_env **env, t_term *term, t_hist **ptr, t_sh *sh)
{
  char		*cpy;
  t_hist	*new;

  if ((normal_mod(env)) == -1)
    return (NULL);
  cpy = manage_new_copy_term(term);
  if ((new = create_new_hist(term, ptr, cpy, sh)) == NULL)
    return (NULL);
  xfree(cpy);
  free_term(term);
  return (new);
}

char	*new_hist(t_env **env, t_hist **ptr, char *prompt, t_sh *sh)
{
  t_hist        *new;
  t_term        *term;

  if ((term = for_begin(env, prompt, ptr)) == NULL)
    return (NULL);
  while (term->flag != ENTER && term->flag != MY_QUIT && term->flag != ALT_A)
    {
      if ((full_term_info(term)) == -1)
        return (NULL);
      if ((manage_buff(term)) == -1)
        return (NULL);
      if ((manage_hist(term, ptr)) == -1)
	return (NULL);
      if (my_strlen(term->str) >= 2048)
	{
	  my_putchar('R');
	  term->flag = ENTER;
	}
      manage_aff(term, env);
    }
  replace_in_hist(term, sh->hist);
  if ((new = for_end(env, term, ptr, sh)) == NULL)
    return (NULL);
  return (new->str);
}
