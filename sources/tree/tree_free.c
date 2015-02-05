/*
** tree_free.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Thu May  3 13:42:14 2012 tom rossi
** Last update Fri May 11 16:32:58 2012 tom rossi
*/

#include <stdlib.h>
#include <tree.h>

void	free_tree(t_tree *tree)
{
  int	i;

  i = 0;
  while (i <= 1)
    {
      if (tree->cmd[i])
	{
	  free_tab(tree->cmd[i]->av);
	  free(tree->cmd[i]->av);
	  free(tree->cmd[i]->data);
	  free(tree->cmd[i]);
	}
      if (tree->next[i])
	free_tree(tree->next[i]);
      i++;
    }
  free(tree);
}
