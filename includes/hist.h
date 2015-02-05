/*
** hist.h for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/includes
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Thu Apr 26 18:00:46 2012 maxime lespagnol
** Last update Wed May 16 13:45:40 2012 maxime lespagnol
*/

#ifndef		__HIST_H__
#define		__HIST_H__

#include        <term_man.h>
#include        <env.h>

typedef struct  s_hist
{
  char          *str;
  char          *copy;
  int           flag;
  int           select;
  struct s_hist *next;
  struct s_hist *prev;
}       t_hist;

void    free_hist(t_hist *hist);
int     manage_hist(t_term *term, t_hist **hist);
char    **add_in_history(char *new, char **hist);
char    *manage_new_copy(t_hist **hist);
char    *manage_new_str(t_hist **hist);
t_term  *create_term_man(t_term *new, char *prompt, char *cpy, t_hist **hist);

#endif
