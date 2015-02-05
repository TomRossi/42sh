/*
** env.c for mysh in /home/rossi_t//random/projets/minishell
**
** Made by tom rossi
** Login   <rossi_t@epitech.net>
**
** Started on  Tue Dec 13 15:38:39 2011 tom rossi
** Last update Sun May 13 15:15:10 2012 tom rossi
*/

#include <stdlib.h>
#include <builtin.h>
#include <env.h>
#include <str.h>

void	freevararg(char *name, char *value)
{
  free(name);
  free(value);
}

int	unset_env(t_env	**env, char *name)
{
  t_env	*tmp;
  t_env	*tmp2;

  tmp = *env;
  if (!tmp)
    return (0);
  if (tmp && match(tmp->name, name))
    {
      freevararg(tmp->name, tmp->value);
      *env = tmp->next;
      free(tmp);
      if (!(*env))
	return (EXIT_SUCCESS);
      return (NO_EXIT);
    }
  while (tmp->next && !match(tmp->next->name, name))
    tmp = tmp->next;
  if (!tmp->next)
    return (EXIT_SUCCESS);
  freevararg(tmp->next->name, tmp->next->value);
  tmp2 = tmp->next;
  tmp->next = tmp->next->next;
  free(tmp2);
  return (NO_EXIT);
}

int	update(t_env **env, char **av)
{
  t_env	*tmp;

  tmp = *env;
  while (tmp && my_strcmp(tmp->name, av[1]))
    tmp = tmp->next;
  if (!tmp)
    return (0);
  free(tmp->value);
  if (!av[2])
    tmp->value = my_strdup("/0");
  else
    tmp->value = my_strdup(av[2]);
  return (1);
}

int	set_env(t_env **env, char **av, int fd)
{
  if (!av[1])
    {
      display(*env, fd);
      return (0);
    }
  if (update(env, av))
    return (EXIT_SUCCESS);
  if (!av[2])
    addvar(env, my_strdup(av[1]), my_strdup("\0"));
  else
    addvar(env, my_strdup(av[1]), my_strdup(av[2]));
  return (EXIT_SUCCESS);
}
