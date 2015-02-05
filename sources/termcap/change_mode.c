/*
** change_mode.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/sources/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Thu May  3 10:37:06 2012 maxime lespagnol
** Last update Thu May  3 10:44:18 2012 maxime lespagnol
*/

#include	<stdlib.h>
#include        <sys/ioctl.h>
#include	<str.h>
#include	<term.h>
#include	<env.h>
#include	<term_man.h>

char    *recup_term(t_env **env)
{
  t_env *ptr;
  char  *term;

  ptr = *env;
  term = NULL;
  while (ptr != NULL && my_strcmp(ptr->name, "TERM") != 0)
    ptr = ptr->next;
  if (ptr != NULL)
    if (my_strcmp(ptr->name, "TERM") == 0)
      if ((term = my_strdup(ptr->value)) == NULL)
        return (NULL);
  return (term);
}

int     term_mod(t_env **env)
{
  char                  *term;
  int                   ret;
  struct termios        t;

  if (tcgetattr(0, &t) == -1)
    return (-1);
  t.c_lflag &= ~ICANON;
  t.c_lflag &= ~ECHO;
  t.c_cc[VMIN] = 1;
  t.c_cc[VTIME] = 0;
  if (tcsetattr(0, 0, &t) == -1)
    return (-1);
  term = recup_term(env);
  if ((ret = tgetent(NULL, term)) == -1)
    return (-1);
  if (ret == 0)
    return (-1);
  xfree(term);
  return (0);
}

int     normal_mod(t_env **env)
{
  struct termios        t;

  if (tcgetattr(0, &t) == -1)
    return (-1);
  t.c_lflag ^= ~ICANON;
  t.c_lflag ^= ~ECHO;
  if (tcsetattr(0, 0, &t) == -1)
    return (-1);
  return (0);
}
