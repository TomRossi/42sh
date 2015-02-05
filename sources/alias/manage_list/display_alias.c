/*
** display_alias.c for display_alias in /home/letexi_a//Documents/Tek1/Projets/42sh/alias
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Mon Apr 30 15:16:01 2012 alexis letexier
** Last update Wed May  9 17:40:00 2012 alexis letexier
*/

#include	<alias.h>

int     my_cmp_alias(char *str, char *cmp)
{
  int	n;
  int	a;

  a = 0;
  n = 0;
  while ((str[n] == '\"' || str[n] == '\'') && str[n] != '\0')
    n++;
  while (str[n] != '\0' && cmp[a] != '\0')
    {
      while (str[n] == cmp[a] && str[n] != '\0' && cmp[a] != '\0')
	{
	  n++;
	  a++;
	}
      if (cmp[a] == '\0')
	return (1);
      else
	{
	  n++;
	  a = 0;
	}
    }
  if (str[n] == '\0')
    return (0);
  return (0);
}

int	display_alias(t_alias **alias, char *str)
{
  t_alias	*tmp;

  tmp = *alias;
  while (tmp != NULL)
    {
      if (my_cmp_alias(tmp->name, str) == 1)
	{
	  my_putstr(tmp->name);
	  my_putstr("\t");
	  my_putstr(tmp->arg);
	  my_putchar('\n');
	}
      tmp = tmp->next;
    }
  return (0);
}
