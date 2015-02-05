/*
** builtins.c for mysh in /home/rossi_t//random/projets/minishell
**
** Made by tom rossi
** Login   <rossi_t@epitech.net>
**
** Started on  Tue Dec 13 10:32:00 2011 tom rossi
** Last update Sat May 19 13:13:11 2012 tom rossi
*/

#include <stdio.h>
#include <stdlib.h>
#include <builtin.h>
#include <tree.h>
#include <str.h>
#include <alias.h>
#include <env.h>
#include <my_glob.h>

int	freeturn(char **tab, int ret)
{
  free_tab(tab);
  free(tab);
  return (ret);
}

int	unsetenv_fail()
{
  fprintf(stderr, "unsetenv: Too few arguments.\n");
  return (EXIT_FAILURE);
}

int	builtins(char **tab, t_env **env, t_sh *sh, int fd)
{
  if (!my_strcmp(tab[0], "exit"))
    return (EXIT_RETURN + (ABS(my_getnbr(tab[1]))));
  else if (!my_strcmp(tab[0], "env"))
    if (tab[1] && !my_strcmp(tab[1], "-i"))
      while (unset_env(env, "*"));
    else
      return (display(*env, fd));
  else if (!my_strcmp(tab[0], "setenv"))
    return (set_env(env, tab, fd));
  else if (!my_strcmp(tab[0], "unsetenv"))
    if (!tab[1])
      return (unsetenv_fail());
    else
      while (unset_env(env, tab[1]) == NO_EXIT);
  else if (!my_strcmp(tab[0], "cd"))
    return (cd(env, tab));
  else if (!my_strcmp(tab[0], "echo"))
    return (echo(tab, fd));
  else if (!my_strcmp(tab[0], B_ALIAS) || !my_strcmp(tab[0], B_UNALIAS))
    return (alias_func(&(sh->alias), tab));
  else if (!my_strcmp(tab[0], B_HISTORY))
    return (aff_history(tab, fd, sh));
  return (EXIT_FAILURE);
}

int	last_builtin(t_cmd *cmd, t_env **env, t_sh *sh, t_pipe *file)
{
  int	fd;

  fd = 1;
  while (file && !(file->type == T_RED && file->mode == M_WRITE))
    file = file->next;
  if (file)
    {
      file->mode = M_VOID;
      fd = file->fd;
    }
  cmd->av = glob_sub(cmd->av, cmd->av_type);
  cmd->av = replace_alias(cmd->av, sh->alias, cmd->av_type);
  return (builtins(cmd->av, env, sh, fd));
}
