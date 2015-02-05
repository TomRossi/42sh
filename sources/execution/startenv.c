/*
** startenv.c for mysh in /home/rossi_t//random/projets/minishell
**
** Made by tom rossi
** Login   <rossi_t@epitech.net>
**
** Started on  Tue Dec 13 13:54:46 2011 tom rossi
** Last update Sat May 19 11:07:26 2012 tom rossi
*/

#include <stdlib.h>
#include <env.h>
#include <str.h>
#include <token.h>

int	addvar(t_env **env, char *var, char *arg)
{
  t_env	*new;

  new = malloc(sizeof(*new));
  if (!new)
    return (RETURN_ERROR);
  new->name = var;
  new->value = arg;
  new->next = *env;
  *env = new;
  return (1);
}
