/*
** tree.c for sh in /home/rossi_t//random/projets/42sh/sources/tree
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Mon Apr 16 13:37:00 2012 tom rossi
** Last update Tue Apr 17 15:09:22 2012 tom rossi
*/

#include <stdlib.h>
#include <tree.h>
#include <token.h>

void	node_null(t_tree *new)
{
  new->cmd[LEFT] = NULL;
  new->cmd[RIGHT] = NULL;
  new->next[LEFT] = NULL;
  new->next[RIGHT] = NULL;
}

int	get_next(int *tab, int *lim)
{
  int	i;
  int	x;

  x = -1;
  i = lim[FROM];
  while (tab[i] && i <= lim[TO])
    {
      if (x < 0 && (tab[i] == T_AND || tab[i] == T_OR))
	return (i);
      i++;
    }
}

int	tree_node(int *tab, int *lim, t_list *list)
{
  t_tree	*new;
  int		nb;
  int		right[2];
  int		left[2];
  int		mid;

  nb = lim[TO] - lim[FROM];
  if (nb <= 0)
    return (RETURN_ERROR);
  if (!(new = malloc(sizeof(*new))))
    exit (1);
  node_null(new);
  middle = get_next(tab, lim)
}
