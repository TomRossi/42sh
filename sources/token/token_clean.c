/*
** token_clean.c for sh in /home/rossi_t//random/projets/42sh/sources
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Wed Apr 18 15:03:50 2012 tom rossi
** Last update Wed May  2 14:18:25 2012 tom rossi
*/

#include <stdlib.h>
#include <token.h>
#include <tree.h>

int	node_kill(t_list **list, t_list *tmp)
{
  t_list	*prev;

  prev = *list;
  if (prev == tmp)
    {
      *list = tmp->next;
      free(prev);
      return (RETURN_SUCCESS);
    }
  while (prev && prev->next != tmp)
    prev = prev->next;
  if (!prev)
    return (RETURN_ERROR);
  prev->next = tmp->next;
  free(tmp);
  return (RETURN_SUCCESS);
}

t_list	*get_close(t_list *_open)
{
  t_list	*tmp;
  int		x;

  x = 0;
  tmp = _open->next;
  while (tmp)
    {
      if (tmp->type == T_BRACKET_O)
	x += 1;
      else if (tmp->type == T_BRACKET_C)
	{
	  if (!x)
	    return (tmp);
	  else
	    x -= 1;
	}
      tmp = tmp->next;
    }
  return (NULL);
}

int	bracket_kill(t_list **list, t_list *_open)
{
  t_list	*_close;
  int		x;

  x = 0;
  _close = _open;
  if (_open->type != T_BRACKET_O)
    return (RETURN_ERROR);
  _close = get_close(_open);
  if (!_close)
    return (RETURN_ERROR);
  node_kill(list, _close);
  node_kill(list, _open);
  return (RETURN_SUCCESS);
}

int	useless(t_list *tmp)
{
  t_list	*end;

  end = tmp;
  end = get_close(tmp);
  if (!end)
    return (RETURN_ERROR);
  while (tmp && tmp != end)
    {
      if (tmp->type == T_OR || tmp->type == T_PIPE || tmp->type == T_SEMICOL
	  || tmp->type == T_AND)
	return (0);
      tmp = tmp->next;
    }
  return (1);
}

int	token_clean(t_list **list)
{
  t_list	*tmp;

  tmp = *list;
  while (tmp)
    {
      if (tmp->type == T_BRACKET_O && useless(tmp))
	bracket_kill(list, tmp);
      tmp = tmp->next;
    }
  return (RETURN_SUCCESS);
}
