/*
** unalias.c for unalias in /home/letexi_a//Documents/Tek1/Projets/42sh
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Wed Apr 18 15:26:29 2012 alexis letexier
** Last update Wed May 16 17:06:08 2012 alexis letexier
*/

#include	<alias.h>

int	delete_first(t_alias *alias, t_alias *tmp)
{
  if (alias->next == NULL)
    return (-1);
  else
    return (1);
}

int	delete_alias(t_alias *alias, char **tab_a, int n)
{
  t_alias *tmp;

  if (alias->next != NULL)
    tmp = alias->next;
  else
    tmp = alias;
  if (my_strcmp(alias->name, tab_a[n]) == 0)
    return (delete_first(alias, tmp));
  while (tmp && my_strcmp(tmp->name, tab_a[n]) != 0 && tmp->next != NULL)
    {
      tmp = tmp->next;
      alias = alias->next;
    }
  if (tmp->next == NULL && my_strcmp(tmp->name, tab_a[n]) == 0)
    {
      alias->next = NULL;
      return (0);
    }
  else if (my_strcmp(tmp->name, tab_a[n]) == 0)
    {
      alias->next = tmp->next;
      return (0);
    }
  return (-2);
}

int	unalias_func(t_alias **alias, char **tab_a)
{
  t_alias	*tmp_a;
  int	n;
  int	tmp;

  n = 1;
  tmp = 0;
  tmp_a = *alias;
  while (tab_a[n] != NULL)
    {
      if (*alias != NULL)
	{
	  tmp = delete_alias(*alias, tab_a, n);
	  if (tmp == -1)
	    *alias = NULL;
	  else if (tmp == 1)
	    *alias = tmp_a->next;
	  else if (tmp == -2)
	    return (RETURN_ERROR);
	}
      else
	return (RETURN_ERROR);
      n++;
    }
  return (RETURN_SUCCESS);
}
