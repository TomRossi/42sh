/*
** tree_utils.c for 42 in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Wed Apr 25 11:41:52 2012 tom rossi
** Last update Sat May 12 20:20:45 2012 tom rossi
*/

#include <stdlib.h>
#include <token.h>
#include <tree.h>

int	middle_node(int type)
{
  if (type == T_PIPE || type == T_IN_S || type == T_OUT_S
      || type == T_OUT_D || type == T_IN_D)
    return (1);
  return (0);
}

int	exec_node(int type)
{
  if (type == T_PIPE || type == T_SEMICOL
      || type == T_AND || type == T_OR || !type)
    return (1);
  return (0);
}

int    send(t_tree *node, t_list *list, int where, t_tree **tree)
{
  if (!get_middle(list))
    {
      node->cmd[where] = tree_cmd(list);
      if (!node->cmd[where])
	return (RETURN_ERROR);
      node->next[where] = NULL;
    }
  else
    {
      node->cmd[where] = NULL;
      node->next[where] = NULL;
      if (tree_node(list, &(node->next[where])) == RETURN_ERROR)
	return (RETURN_ERROR);
    }
  return (RETURN_SUCCESS);
}

int     valid_red(t_list *tmp)
{
  int   next;

  if (!tmp->next->next)
    return (TRUE);
  next = tmp->next->next->type;
  if (next == T_SEMICOL || next == T_BRACKET_C)
    return (TRUE);
  if (next == T_AND || next == T_OR)
    return (TRUE);
  return (FALSE);
}

int	is_redir(t_tree *tmp)
{
  int	type;

  type = tmp->type;
  if (type && type != T_AND && type != T_OR &&
      type != T_SEMICOL && type != T_PIPE)
    return (TRUE);
  return (FALSE);
}
