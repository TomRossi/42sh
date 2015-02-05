/*
** list_alias.c for list_alias in /home/letexi_a//Documents/Tek1/Projets/42sh
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Tue Mar 27 15:26:36 2012 alexis letexier
** Last update Mon May 14 17:50:04 2012 alexis letexier
*/

#include	<alias.h>

int	my_alias_to_list(t_alias **alias, char *name, char *arg)
{
  t_alias	*element;
  int   i;

  i = 0;
  element = malloc(sizeof(*element));
  if (element == NULL)
    return (RETURN_ERROR);
  if (name != NULL)
    element->name = name;
  if (arg != NULL)
    element->arg = arg;
  element->pos = 0;
  element->next = *alias;
  *alias = element;
  return (RETURN_SUCCESS);
}

int	list_alias(t_alias **alias, char *name, char *arg)
{
  if (my_alias_to_list(alias, name, arg) == RETURN_ERROR)
    return (RETURN_ERROR);
  return (RETURN_SUCCESS);
}
