/*
** tree_pass.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Sun May 13 13:46:16 2012 tom rossi
** Last update Sat May 19 13:06:13 2012 tom rossi
*/

#include <stdio.h>
#include <stdlib.h>
#include <tree.h>
#include <token.h>

int	valid_or(int *_ret)
{
  int	ret;

  ret = *_ret;
  if (ret == AND_SUCCESS)
    *_ret = OR_FAIL;
  else if (ret == OR_SUCCESS)
    *_ret = OR_SUCCESS;
  else if (ret == RETURN_SUCCESS)
    *_ret = OR_SUCCESS;
  else
    {
      *_ret = OR_SUCCESS;
      return (RETURN_SUCCESS);
    }
  return (RETURN_ERROR);
}

int	valid_and(int *_ret)
{
  int	ret;

  ret = *_ret;
  if (ret == OR_SUCCESS)
    *_ret = AND_SUCCESS;
  else if (ret == RETURN_SUCCESS)
    *_ret = RETURN_SUCCESS;
  else
    {
      *_ret = AND_FAIL;
      return (RETURN_ERROR);
    }
  *_ret = AND_SUCCESS;
  return (RETURN_SUCCESS);
}

int     valid_return(int *_ret, int type)
{
  if (type == T_OR)
    return (valid_or(_ret));
  else if (type == T_AND)
    return (valid_and(_ret));
  return (RETURN_SUCCESS);
}

int     not_a_pipe(t_tree *tree, t_pipe **pipe, t_sh *sh, int dad)
{
  int   i;
  int   ret;

  i = 0;
  if (tree->cmd[LEFT])
    ret = no_fork(tree, pipe, sh, LEFT);
  else
    ret = tree_explore(tree->next[LEFT], pipe, sh, 0);
  if (ret == BYE)
    return (ret);
  if (valid_return(&ret, tree->type) == RETURN_ERROR)
    return (ret);
  if (tree->cmd[RIGHT])
    ret = no_fork(tree, pipe, sh, RIGHT);
  else
    ret = tree_explore(tree->next[RIGHT], pipe, sh, 0);
  return (ret);
}
