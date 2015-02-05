/*
** token_list.c for 42 in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Wed Apr 18 11:53:00 2012 tom rossi
** Last update Wed May  9 16:20:51 2012 tom rossi
*/

#include <stdlib.h>
#include <tree.h>
#include <token.h>

int	new_list(t_list **new, int type)
{
  t_list	*tmp;
  t_list	*last;

  last = *new;
  while (last && last->next)
    last = last->next;
  if (!(tmp = malloc(sizeof(*tmp))))
    return (RETURN_ERROR);
  tmp->is_data = 0;
  tmp->type = type;
  tmp->mode = M_NONE;
  tmp->next = NULL;
  tmp->prev = NULL;
  if (!last)
    *new = tmp;
  else
    {
      tmp->prev = last;
      last->next = tmp;
    }
  return (RETURN_SUCCESS);
}

void	edit_list(t_list *tmp, t_list **new)
{
  t_list	*last;

  last = *new;
  while (last && last->next)
    last = last->next;
  tmp->is_data = 1;
  tmp->next = NULL;
  tmp->prev = NULL;
  if (!last)
    *new = tmp;
  else
    {
      tmp->prev = last;
      last->next = tmp;
    }
}

void	init_list(t_list **tmp, t_list **new, int *i, t_list **list)
{
  *tmp = *list;
  *new = NULL;
  *i = 0;
}

t_list	*set_edit(t_list *tmp, t_list **new, int x)
{
  t_list	*tmp2;

  tmp->type = x;
  tmp2 = tmp->next;
  edit_list(tmp, new);
  tmp = tmp2;
  return (tmp);
}

int	token_list(int *tab, t_list **list)
{
  int		i;
  t_list	*tmp;
  t_list	*new;

  init_list(&tmp, &new, &i, list);
  while (tab[i] && tab[i] == T_SEMICOL)
    i += 1;
  if (!tab[i])
    return (RETURN_ERROR);
  while (tab[i])
    {
      if (tmp && i == tmp->rank)
	tmp = set_edit(tmp, &new, tab[i]);
      else if (!(tab[i] == T_SEMICOL && !tab[i + 1]))
	if (new_list(&new, tab[i]) == RETURN_ERROR)
	  return (RETURN_ERROR);
      i++;
      while (tab[i] && tab[i] == T_SEMICOL && tab[i + 1] == T_SEMICOL)
	i++;
    }
  *list = new;
  return (RETURN_SUCCESS);
}
