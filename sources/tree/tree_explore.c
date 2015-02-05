/*
** tree_explore.c for  in /home/rossi_t//random/projets/42sh/sources
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Wed Apr 18 20:38:50 2012 tom rossi
** Last update Fri May 18 19:55:12 2012 tom rossi
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <tree.h>
#include <builtin.h>
#include <token.h>
#include <env.h>

int	f_exec(t_cmd *cmd, t_pipe **pipe, t_sh *sh, int group)
{
  int	pid;
  int	status;

  pid = fork();
  if (!pid)
    {
      if (group)
	setpgid(0, tcgetpgrp(0));
      else
	new_group();
      execute_(cmd, pipe, sh);
    }
  else
    {
      close_pipe(*pipe);
      waitpid(pid, &status, 0);
      return (display_status(&status, 0));
    }
  return (BYE);
}

int	no_fork(t_tree *tree, t_pipe **pipe, t_sh *sh, int to)
{
  if (tree->cmd[to])
    {
      if (tree->cmd[to]->type == T_BUILT)
	return (execute_(tree->cmd[to], pipe, sh));
      else
	return (f_exec(tree->cmd[to], pipe, sh, 0));
    }
  return (RETURN_ERROR);
}

int	tree_action(t_tree *tree, t_pipe **pipe, t_sh *sh, int dad)
{
  int	ret;

  if (is_redir(tree) == TRUE)
    {
      if (!tree->next[LEFT] && tree->cmd[LEFT])
	{
	  if (dad || tree->cmd[LEFT]->type != T_BUILT)
	    ret = no_fork(tree, pipe, sh, LEFT);
	  else
	    ret = last_builtin(tree->cmd[LEFT], &(sh->env), sh, *pipe);
	}
      else
	ret = tree_explore(tree->next[LEFT], pipe, sh, dad);
      return (ret);
    }
  else if (tree->type != T_PIPE)
    return (not_a_pipe(tree, pipe, sh, dad));
  else
    return (exec_pipe(tree, pipe, sh, dad));
  return (RETURN_ERROR);
}

int	tree_explore(t_tree *tree, t_pipe **pipe, t_sh *sh, int dad)
{
  int	ret;

  if (middle_node(tree->type))
    if (tree_pipe(pipe, tree->type, tree) == RETURN_ERROR)
      return (EXIT_FAILURE);
  if (!tree->type)
    return (no_fork(tree, pipe, sh, LEFT));
  ret = tree_action(tree, pipe, sh, dad);
  return (ret);
}

int	my_sh(t_tree *tree, t_sh *sh)
{
  t_pipe	*pipe;
  int		ret;

  pipe = NULL;
  ret = tree_explore(tree, &pipe, sh, 0);
  if (ret == BYE)
    return (BYE);
  else if (ret >= EXIT_RETURN)
    {
      set_env_return(sh, ret);
      return (ret - EXIT_RETURN);
    }
  set_env_return(sh, ret);
  return (NO_EXIT);
}
