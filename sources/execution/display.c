/*
** display.c for mysh in /home/rossi_t//random/projets/minishell
**
** Made by tom rossi
** Login   <rossi_t@epitech.net>
**
** Started on  Mon Dec 12 18:50:53 2011 tom rossi
** Last update Sun May 13 15:15:53 2012 tom rossi
*/

#include <stdlib.h>
#include <env.h>
#include <str.h>

int	display(t_env *env, int fd)
{
  t_env	*tmp;

  tmp = env;
  if (!env)
    return (0);
  if (env->next)
    display(env->next, fd);
  my_putfd(tmp->name, fd);
  my_putfd("=", fd);
  my_putfd(tmp->value, fd);
  my_putfd("\n", fd);
  return (EXIT_SUCCESS);
}
