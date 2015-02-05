/*
** action.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Fri May 18 15:45:04 2012 tom rossi
** Last update Fri May 18 15:45:05 2012 tom rossi
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <term.h>
#include <sys/ioctl.h>
#include <str.h>
#include <hist.h>
#include <env.h>
#include <token.h>
#include <errors.h>
#include <get_next_line.h>
#include <tree.h>
#include <term_man.h>

int     str_token(char *buf, t_sh *sh, t_list **list)
{
  int   *tok;

  tok = NULL;
  tok = token(buf, list);
  if (!tok)
    return (RETURN_ERROR);
  if (token_list(tok, list) == RETURN_ERROR || !list)
    return (RETURN_ERROR);
  if (!tok[0])
    return (RETURN_ERROR);
  if (error_management(tok, 0) == RETURN_ERROR)
    return (RETURN_ERROR);
  free(tok);
  return (RETURN_SUCCESS);
}

int     str_action(char *buf, t_sh *sh)
{
  int           ret;
  t_list        *list;
  t_tree        *tree;

  list = NULL;
  if (str_token(buf, sh, &list) == RETURN_ERROR)
    return (NO_EXIT);
  if (redirect_set(list) == RETURN_ERROR)
    return (NO_EXIT);
  token_redirect(&list);
  if (tree_build(&tree, list) == RETURN_ERROR)
    {
      return (NO_EXIT);
    }
  ret = my_sh(tree, sh);
  free_list(list);
  free_tree(tree);
  return (ret);
}
