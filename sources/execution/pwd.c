/*
** pwd.c for mysh in /home/rossi_t//random/projets/minishell
**
** Made by tom rossi
** Login   <rossi_t@epitech.net>
**
** Started on  Tue Dec 20 11:17:22 2011 tom rossi
** Last update Sat May 19 13:02:36 2012 tom rossi
*/

#include <stdio.h>
#include <stdlib.h>
#include <env.h>
#include <builtin.h>
#include <str.h>

int     pwd(t_env **env, char **av)
{
  t_env *tmp;
  t_env *old;

  old = *env;
  tmp = *env;
  while (tmp && my_strcmp(tmp->name, "PWD"))
    tmp = tmp->next;
  while (old && my_strcmp(old->name, "OLDPWD"))
    old = old->next;
  if (!tmp)
    return (RETURN_SUCCESS);
  if (old)
    {
      if (old->value)
	free(old->value);
      old->value = tmp->value;
    }
  else if (tmp)
    addvar(env, my_strdup("OLDPWD"), tmp->value);
  if (tmp)
    if (tmp->value)
      tmp->value = definepwd(av[1], tmp->value);
  if (av[2] && !my_strcmp(av[2], "-l"))
    printf("%s\n", tmp->value);
  return (RETURN_SUCCESS);
}
