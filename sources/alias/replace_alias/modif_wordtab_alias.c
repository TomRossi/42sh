/*
** modif_wordtab_alias.c for modif_wordtab_alias in /home/letexi_a//Documents/Tek1/Projets/42sh/alias/replace_alias
** 
** Made by alexis letexier
** Login   <letexi_a@epitech.net>
** 
** Started on  Wed May  2 09:21:32 2012 alexis letexier
** Last update Thu May 17 10:26:19 2012 alexis letexier
*/

#include	<alias.h>
#include	<env.h>

int	tab_len(char **tmp)
{
  int	n;

  n = 0;
  if (tmp != NULL)
    {
      while (tmp[n] != NULL)
	n++;
    }
  return (n);
}

void	copy_to_wordtab(char *str, char *tab_a)
{
  int	n;

  n = 0;
  while (str[n] != '\0')
    {
      tab_a[n] = str[n];
      n++;
    }
  tab_a[n] = '\0';
}

int	check_same_arg(char **arg, int i, char **tmp)
{
  int	n;

  n = 0;
  while (tmp[n] != NULL && arg[i] != NULL && my_strcmp(tmp[n], arg[i]) == 0)
    {
      i++;
      n++;
    }
  if (tmp[n] == NULL)
      return (-1);
  return (0);
}

char	**modif_wordtab_alias(char **arg, int i, int a, t_alias *alias)
{
  int	n;
  char	**ret;
  char	**tmp;

  ret = NULL;
  n = 0;
  tmp = my_wordtab(alias->arg);
  if (tmp != NULL && check_same_arg(arg, i, tmp) != -1)
    {
      ret = malloc(sizeof(*ret) * (tab_len(tmp) + tab_len(arg)));
      if (ret == NULL)
	return (NULL);
      n = copy_start_alias(ret, arg, n, i);
      if (n == -1)
	return (NULL);
      n = copy_int_alias(tmp, ret, n);
      if (n == -1)
	return (NULL);
      n = copy_end_alias(ret, n, arg, a);
      if (n == -1)
	return (NULL);
      ret[n] = NULL;
      free_tab(tmp);
    }
  return (ret);
}
