/*
** add_alias.c for add_alias.c in /home/letexi_a//Documents/Tek1/Projets/42sh
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Wed Mar 28 10:06:00 2012 alexis letexier
** Last update Mon May 14 17:50:24 2012 alexis letexier
*/

#include	<alias.h>

int     check_alias(t_alias *alias, char *name)
{
  while (alias->next != NULL)
    {
      if (my_strcmp(alias->name, name) == 0)
        return (1);
      alias = alias->next;
    }
  if (my_strcmp(alias->name, name) == 0)
    return (1);
  return (0);
}

int     modif_alias(t_alias *alias, char *name, char *arg)
{
  while (my_strcmp(alias->name, name) != 0 && alias->next != NULL)
    alias = alias->next;
  alias->arg = arg;
  return (0);
}

int	add_alias(t_alias **alias, char *name, char *arg)
{
  t_alias       *element;
  t_alias	*tmp;

  element = malloc(sizeof(*element));
  if (element == NULL)
    return (RETURN_ERROR);
  if (check_alias(*alias, name) == 0)
    {
      element->name = name;
      element->arg = arg;
      element->pos = 0;
      element->next = NULL;
      tmp = *alias;
      while (tmp->next != NULL)
        tmp = tmp->next;
      tmp->next = element;
    }
  else
    modif_alias(*alias, name, arg);
  return (RETURN_SUCCESS);
}

int	manage_add_alias(t_alias **alias, char **tab_a)
{
  char	*arg;

  if (tab_a != NULL)
    arg = concat_arg_alias(tab_a);
  if (*alias == NULL && tab_a[1] != NULL && arg != NULL)
    {
      if (list_alias(alias, my_strdup(tab_a[1]), arg)
	  == RETURN_ERROR)
	return (RETURN_ERROR);
    }
  else if (*alias != NULL && tab_a[1] != NULL && tab_a[2] != NULL)
    {
      if (add_alias(alias, my_strdup(tab_a[1]), arg)
	  == RETURN_ERROR)
	return (RETURN_ERROR);
    }
  return (RETURN_SUCCESS);
}
