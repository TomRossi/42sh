/*
** red_set.c for sh$ in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Mon Apr 30 17:25:01 2012 tom rossi
** Last update Mon Apr 30 17:29:17 2012 tom rossi
*/

#include <stdio.h>
#include <token.h>
#include <tree.h>

int     redirect_type(t_list *list)
{
  if (!list->prev)
    {
      printf("Ambigous redirection.\n");
      return (RETURN_ERROR);
    }
  list->type = T_RED;
  list->red_type = list->prev->type;
  return (RETURN_SUCCESS);
}

int	redirect_set(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->type == T_RED)
	{
	  if (redirect_type(tmp) == RETURN_ERROR)
	    return (RETURN_ERROR);
	}
      tmp = tmp->next;
    }
  return (RETURN_SUCCESS);
}
