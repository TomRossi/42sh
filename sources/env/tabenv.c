/*
** tabenv.c for mysh in /home/rossi_t//random/projets/minishell
**
** Made by tom rossi
** Login   <rossi_t@epitech.net>
**
** Started on  Wed Dec 14 17:13:07 2011 tom rossi
** Last update Wed May  2 15:00:42 2012 tom rossi
*/

#include <stdlib.h>
#include <str.h>
#include <env.h>

int	list_size(t_env *env)
{
  t_env	*tmp;
  int	i;

  i = 0;
  tmp = env;
  while (tmp)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}

char	**tabenv(t_env *env)
{
  char	**tab;
  int	x;
  char	*s;

  if (!env)
    return (NULL);
  tab = malloc(sizeof(*tab) * (list_size(env) + 2));
  if (!tab)
    return (NULL);
  x = 0;
  while (env)
    {
      s = my_strcat(env->name, "=");
      tab[x] = my_strcat(s, env->value);
      free(s);
      x++;
      env = env->next;
    }
  tab[x] = NULL;
  return (tab);
}
