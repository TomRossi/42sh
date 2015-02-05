/*
** token_redirect.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Fri Apr 27 17:28:50 2012 tom rossi
** Last update Wed May  2 14:16:19 2012 tom rossi
*/

#include <stdlib.h>
#include <token.h>
#include <tree.h>

int	is_red(t_list *tmp)
{
  int	type;

  if (!tmp)
    return (FALSE);
  type = tmp->type;
  if (type != T_IN_S && type != T_IN_D
      && type != T_OUT_S && type != T_OUT_D)
    return (FALSE);
  return (TRUE);
}

void	push_red(t_list *tmp)
{
  t_list	*red;
  t_list	*file;
  t_list	*after;
  t_list	*last;

  red = tmp->next;
  file = red->next;
  after = file->next;
  last = after->next;
  red->prev = after;
  file->next = last;
  tmp->next = after;
  after->next = red;
  after->prev = tmp;
  if (last)
    last->prev = file;
}

int	move_red(t_list *tmp)
{
  int	i;

  i = 0;
  while (valid_red(tmp->next) == FALSE)
    {
      push_red(tmp);
      tmp = tmp->next;
    }
  return (RETURN_SUCCESS);
}

void	move_first_red(t_list **list)
{
  t_list	*red;
  t_list	*file;
  t_list	*after;
  t_list	*last;

  red = *list;
  file = red->next;
  after = file->next;
  last = after->next;
  file->next = last;
  red->prev = after;
  *list = after;
  after->prev = NULL;
  after->next = red;
  if (last)
    last->prev = file;
}

int	token_redirect(t_list **list)
{
  t_list	*tmp;

  if (is_red(*list) && valid_red(*list) == FALSE)
    move_first_red(list);
  tmp = *list;
  while (tmp && tmp->next)
    {
      if (is_red(tmp->next) == TRUE && valid_red(tmp->next) == FALSE)
	move_red(tmp);
      tmp = tmp->next;
    }
  return (RETURN_SUCCESS);
}
