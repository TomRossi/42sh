/*
** tree_set.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Wed May  2 16:53:04 2012 tom rossi
** Last update Thu May  3 11:07:28 2012 tom rossi
*/

#include <stdio.h>
#include <stdlib.h>
#include <token.h>
#include <tree.h>

int     tree_build(t_tree **tree, t_list *list)
{
  int	ret;

  *tree = NULL;
  ret = tree_node(list, tree);
  return (ret);
}
