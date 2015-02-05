/*
** glob_sub.c for sh in /home/rossi_t//random/projets/42sh/svn/Teddy/MY_GLOB
**
** Made by tom rossi
** Login   <rossi_t@epitech.net>
**
** Started on  Fri May 11 17:29:51 2012 tom rossi
** Last update Sat May 19 11:57:15 2012 tom rossi
*/

#include        <glob.h>
#include        <stdio.h>
#include        <string.h>
#include        <stdlib.h>
#include	<str.h>
#include	<env.h>
#include	<token.h>
#include        <my_glob.h>

int	tab_size(char **tab)
{
  int	i;

  if (!tab)
    return (0);
  i = 0;
  while (tab && tab[i])
    i++;
  return (i);
}

int	alloc_size(char **tab, char **tmp)
{
  int	x;

  if (!tmp)
    x = 0;
  else
    x = tab_size(tmp);
  if (!x)
    x++;
  x++;
  if (tab)
    x += tab_size(tab);
  return (x);
}

void	init_glob(int *i, int *a, char ***out)
{
  *i = 0;
  *a = 0;
  *out = NULL;
}

void	free_please(char **tab)
{
  free_tab(tab);
  free(tab);
}

char	**glob_sub(char **tab, int *type)
{
  char	**tmp;
  char	**out;
  int	v[3];

  init_glob(&(v[G_I]), &(v[G_A]), &out);
  while (tab[v[G_I]] && !(v[G_X] = 0))
    {
      if (type[v[G_I]] == M_NORMAL)
	tmp = my_func_glob(tab[v[G_I]]);
      else
	tmp = NULL;
      out = realloc(out, sizeof(*tab) * alloc_size(out, tmp));
      if (!tmp)
	out[(v[G_A])++] = my_strdup(tab[v[G_I]]);
      while (tmp && tmp[v[G_X]])
	out[(v[G_A])++] = my_strdup(tmp[(v[G_X])++]);
      out[(v[G_A])] = NULL;
      free_tab(tmp);
      free(tmp);
      (v[G_I])++;
    }
  out[v[G_A]] = NULL;
  free_tab(tab);
  free(tab);
  return (out);
}
