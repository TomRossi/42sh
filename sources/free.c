/*
** free.c for mysh in /home/rossi_t//random/projets/minishell
**
** Made by tom rossi
** Login   <rossi_t@epitech.net>
**
** Started on  Mon Dec 12 18:20:10 2011 tom rossi
** Last update Wed May 16 15:42:01 2012 alexis letexier
*/

#include <stdlib.h>
#include <tree.h>
#include <token.h>
#include <env.h>
#include <hist.h>
#include <alias.h>

int	free_tab(char **tab)
{
  int	i;

  if (!tab)
    return (0);
  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  return (1);
}

void	free_alias(t_alias *alias)
{
  if (alias && alias->next)
    free_alias(alias->next);
  if (alias)
    {
      free(alias->name);
      free(alias->arg);
      free(alias);
    }
}

void	free_hist(t_hist *hist)
{
  if (hist && hist->next)
    free_hist(hist->next);
  if (hist)
    {
      free(hist->str);
      free(hist->copy);
      free(hist);
    }
}

void	free_list(t_list *list)
{
  if (list && list->next)
    free_list(list->next);
  if (list)
    {
      if (list->data)
	free(list->data);
      free(list);
    }
}

void	free_env(t_env *env)
{
  if (env && env->next)
    free_env(env->next);
  if (env)
    {
      free(env->name);
      free(env->value);
      free(env);
    }
}
