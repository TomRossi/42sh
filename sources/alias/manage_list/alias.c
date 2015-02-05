/*
** alias.c for alias.c in /home/letexi_a//Documents/Tek1/Projets/42sh
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Tue Apr 17 10:13:26 2012 alexis letexier
** Last update Wed May 16 17:15:05 2012 alexis letexier
*/

#include	<alias.h>

int     find_alias_type_2(char **tab_a)
{
  if (my_strcmp(tab_a[0], "alias") == 0)
    {
      if (my_strcmp(tab_a[1], "-p") == 0)
        return (2);
      else
        return (3);
    }
  return (-1);
}

int     find_alias_type(char **tab_a)
{
  int	n;

  n = 0;
  while (tab_a[n] != NULL)
    n++;
  if (n >= 3 && my_strcmp(tab_a[0], "alias") == 0)
    return (0);
  if (n >= 2)
    {
      if (my_strcmp(tab_a[0], "unalias") == 0)
        return (1);
      else if (n == 2)
        return (find_alias_type_2(tab_a));
      else
        return (-1);
    }
  if (n == 1 && my_strcmp(tab_a[0], "alias") == 0)
    return (2);
  return (-1);
}

int     alias_inter_func(t_alias **alias, char **tab_a)
{
  int   type;

  type = find_alias_type(tab_a);
  if (type == 0)
    {
      if (manage_add_alias(alias, tab_a) == RETURN_ERROR)
        return (EXIT_FAILURE);
    }
  else if (type == 3)
    display_alias(alias, my_strdup(tab_a[1]));
  else if (type == 2)
    my_show_alias(*alias);
  else if (type == 1)
    {
      if (unalias_func(alias, tab_a) == RETURN_ERROR)
        return (EXIT_FAILURE);
    }
  else if (type == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int     alias_func(t_alias **alias, char **tab_a)
{
  if (tab_a != NULL)
    {
      if (error_alias(tab_a) == 0)
	{
	  if (alias_inter_func(alias, tab_a) == RETURN_ERROR)
	    return (EXIT_FAILURE);
	  else
	    return (EXIT_SUCCESS);
	}
      else
	return (EXIT_FAILURE);
    }
  else
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
