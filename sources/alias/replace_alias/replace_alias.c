/*
** replace_alias.c for replace_alias in /home/letexi_a//Documents/Tek1/Projets/42sh/alias/replace_alias
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Tue May  1 14:47:12 2012 alexis letexier
** Last update Fri May 18 13:02:46 2012 tom rossi
*/

#include	<alias.h>
#include	<token.h>
#include	<env.h>

char	**verif_alias_replace(char **arg, char *tmp, t_alias *alias)
{
  char	**ret;
  int	i;

  i = 0;
  ret = NULL;
  if (arg[0] != NULL)
   {
      if (my_strcmp(arg[0], tmp) != 0)
	return (NULL);
    }
  alias->pos = alias->pos + 1;
  if (my_strcmp(alias->name, alias->arg) != 0)
    ret = modif_wordtab_alias(arg, i, 1, alias);
  return (ret);
}

char	**cmp_replace_alias(char **arg, t_alias *alias)
{
  char	**ret;

  ret = NULL;
  if (arg[0] != NULL)
    {
      if (my_strcmp(alias->name, arg[0]) == 0)
	ret = verif_alias_replace(arg, alias->name, alias);
    }
  if (ret != NULL)
    return (ret);
  return (ret);
}

char	**find_alias_replace(char **arg, t_alias *alias)
{
  char	**ret;
  t_alias	*tmp;

  tmp = alias;
  ret = NULL;
  while (tmp != NULL && tmp->pos <= 2)
    {
      ret = cmp_replace_alias(arg, tmp);
      if (ret != NULL)
	return (ret);
      tmp = tmp->next;
    }
  return (NULL);
}

int    init_pos_alias(t_alias *alias)
{
  int	compt;
  t_alias       *tmp;

  compt = 0;
  tmp = alias;
  if (tmp != NULL)
    {
      while (tmp != NULL)
	{
	  if (tmp->pos > compt)
	    compt = tmp->pos;
	  tmp->pos = 0;
	  tmp = tmp->next;
	}
      if (compt > 2)
	{
	  my_putfd("alias loop.\n", 2);
	  return (-1);
	}
    }
  return (0);
}

char	**replace_alias(char **arg, t_alias *alias, int *type)
{
  char **tmp;
  char **ret;

  ret = NULL;
  if (arg != NULL && type != NULL && type[0] == M_NORMAL)
    {
      tmp = find_alias_replace(arg, alias);
      if (tmp != NULL)
	ret = tmp;
      while (tmp != NULL)
	{
	  tmp = find_alias_replace(tmp, alias);
	  if (tmp != NULL)
	    ret = tmp;
	}
      if (ret != NULL && init_pos_alias(alias) != -1)
	{
	  free_tab(arg);
	  return (ret);
	}
    }
  return (arg);
}
