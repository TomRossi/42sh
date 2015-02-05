/*
** create_new.c for 42sh in /home/lespag_m//Documents/Unix/42sh/Perso/termcap
** 
** Made by maxime lespagnol
** Login   <lespag_m@epitech.net>
** 
** Started on  Tue May  1 21:11:44 2012 maxime lespagnol
** Last update Thu May 17 10:05:34 2012 alexis letexier
*/

#include	<stdlib.h>
#include	<term.h>
#include	<hist.h>
#include	<str.h>
#include	<lib.h>
#include	<term_man.h>

void    mod_hist(t_hist **hist, t_sh *sh);

char	*manage_new_copy_term(t_term *ptr)
{
  char	*ret;

  ret = NULL;
  if (ptr->copy != NULL)
    ret = my_strdup(ptr->copy);
  return (ret);
}

char	*manage_new_copy(t_hist **hist)
{
  t_hist	*tmp;
  char		*ret;

  tmp = *hist;
  ret = NULL;
  if (tmp != NULL && tmp->copy != NULL)
    ret = my_strdup(tmp->copy);
  if (tmp != NULL && tmp->copy == NULL)
    ret = NULL;
  return (ret);
}

t_term  *create_term_man(t_term *new, char *prompt, char *cpy, t_hist **hist)
{
  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->flag = NOTH;
  new->str = manage_new_str(hist);
  new->str_cr = NULL;
  new->flag_cr = 1;
  new->buff = NULL;
  new->copy = NULL;
  new->copy = my_strdup(cpy);
  new->s_pr = my_strlen(prompt);
  new->pos = my_strlen(new->str);
  if ((new->prompt = my_strdup(prompt)) == NULL)
    return (NULL);
  return (new);
}

void	aff_enter_please(t_term *ptr)
{
  go_begin(ptr);
  my_putstr(tgetstr("cd", NULL));
  my_putstr(ptr->str);
  my_putchar('\n');
}

t_hist  *create_new_hist(t_term *term, t_hist **ptr, char *cpy, t_sh *sh)
{
  t_hist	*new;

  if ((new = malloc(sizeof(*new))) != NULL)
    {
      new->next = *ptr;
      if ((*ptr) != NULL)
        ((*ptr)->prev) = new;
      new->prev = NULL;
      new->flag = term->flag;
      new->copy = my_strdup(cpy);
      new->select = 1;
      if (term->str == NULL && (term->flag == ENTER || term->flag == ALT_A))
        if ((new->str = my_strdup("\0")) == NULL)
          return (NULL);
      if ((new->str = my_strdup(term->str)) == NULL)
        return (NULL);
      *ptr = new;
      aff_enter_please(term);
      mod_hist(ptr, sh);
      return (new);
    }
  return (NULL);
}
