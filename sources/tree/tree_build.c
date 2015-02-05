/*
** tree.c for sh in /home/rossi_t//random/projets/42sh/sources/tree
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Mon Apr 16 13:37:00 2012 tom rossi
** Last update Thu May 17 12:04:15 2012 tom rossi
*/

#include <stdio.h>
#include <stdlib.h>
#include <tree.h>
#include <token.h>

t_list	*get_mid_type(t_list *list, int type)
{
  t_list	*tmp;

  tmp = list;
  while (tmp && tmp->next)
    tmp = tmp->next;
  while (tmp)
    {
      if (tmp->type == type)
	return (tmp);
      tmp = tmp->prev;
    }
  return (NULL);
}

t_list	*get_red(t_list *list)
{
  t_list	*tmp;
  int		type;

  tmp = list;
  while (tmp && tmp->next)
    tmp = tmp->next;
  while (tmp)
    {
      type = tmp->type;
      if (type == T_IN_S || type == T_IN_D
	  || type == T_OUT_S || type == T_OUT_D)
	return (tmp);
      tmp = tmp->prev;
    }
  return (tmp);
}

t_list	*get_middle(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp && tmp->next)
    tmp = tmp->next;
  while (tmp)
    {
      if (tmp->type == T_OR || tmp->type == T_AND || tmp->type == T_SEMICOL)
	return (tmp);
      tmp = tmp->prev;
    }
  tmp = get_red(list);
  if (tmp)
    return (tmp);
  tmp = get_mid_type(list, T_PIPE);
  if (tmp)
    return (tmp);
  return (NULL);
}

t_cmd	*tree_cmd(t_list *list)
{
  t_cmd	*new;

  new = malloc(sizeof(*new));
  if (!new || !list)
    return (NULL);
  new->type = list->type;
  while (list && (list->type == T_BRACKET_O || list->type == T_BRACKET_C))
    list = list->next;
  if (!list)
    return (NULL);
  new->av = build_av(list);
  new->av_type = build_av_type(list);
  if (!new->av)
    return (NULL);
  if (is_builtin(new->av[0]) == RETURN_SUCCESS)
    new->type = T_BUILT;
  new->data = my_strdup(list->data);
  return (new);
}

int	tree_node(t_list *list, t_tree **tree)
{
  t_tree	*node;
  t_list	*mid;

  node = malloc(sizeof(*node));
  if (!node || !list)
    return (RETURN_ERROR);
  if (!(*tree))
    *tree = node;
  mid = get_middle(list);
  if (!mid)
    {
      node->type = 0;
      if (send(node, list, LEFT, tree) == RETURN_ERROR)
	return (RETURN_ERROR);
      node->cmd[RIGHT] = NULL;
      node->next[RIGHT] = NULL;
      return (RETURN_SUCCESS);
    }
  node->ret = V_NONE;
  node->type = mid->type;
  mid->prev->next = NULL;
  mid->next->prev = NULL;
  if (send(node, list, LEFT, tree) || send(node, mid->next, RIGHT, tree))
    return (RETURN_ERROR);
  return (RETURN_SUCCESS);
}
