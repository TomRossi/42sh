/*
** tree_execute.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Thu Apr 26 20:02:13 2012 tom rossi
** Last update Sat May 19 10:26:45 2012 tom rossi
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <tree.h>
#include <token.h>
#include <builtin.h>
#include <alias.h>
#include <my_glob.h>
#include <env.h>

int     close_pipe(t_pipe *_pipe)
{
  t_pipe        *tmp;

  tmp = _pipe;
  while (tmp && tmp->mode != M_READ)
    tmp = tmp->next;
  if (!tmp)
    return (0);
  close(tmp->p[1]);
  return (1);
}

int     execute_(t_cmd *cmd, t_pipe **_pipe, t_sh *sh)
{
  cmd->av = token_envsub(cmd->av, sh->env, cmd->av_type);
  cmd->av = glob_sub(cmd->av, cmd->av_type);
  cmd->av = replace_alias(cmd->av, sh->alias, cmd->av_type);
  dup_pipe(_pipe, cmd->type);
  if (bin_cmd(cmd, sh->env) == RETURN_ERROR)
    return (EXEC_FAIL);
  if (cmd->type == T_BUILT)
    return (builtins(cmd->av, &(sh->env), sh, 1));
  else
    {
      if (execve(cmd->path, cmd->av, tabenv(sh->env)) < 0)
	exit(EXIT_FAILURE);
    }
  return (EXEC_FAIL);
}

int	exec_left(t_tree *tree, t_pipe **pipe, t_sh *sh, int dad)
{
  if (tree->next[LEFT])
    return (tree_explore(tree->next[LEFT], pipe, sh, dad + 1));
  else
    return (execute_(tree->cmd[LEFT], pipe, sh));
}

int	exec_right(t_tree *tree, t_pipe **pipe, t_sh *sh, int dad)
{
  int	gp;

  kill_red_read(pipe);
  gp = 0;
  if (!dad)
    while ((gp = tcgetpgrp(0)) == getpgid(0));
  close_pipe(*pipe);
  if ((*pipe) && (*pipe)->type == T_PIPE)
    (*pipe)->mode = M_READ;
  if (tree->type != T_PIPE && tree->type != T_SEMICOL &&
      tree->type != T_OR && tree->type != T_AND)
    return (EXIT_SUCCESS);
  if (tree->next[RIGHT])
    return (tree_explore(tree->next[RIGHT], pipe, sh, dad + 1));
  else if (tree->cmd[RIGHT])
    {
      if (dad || tree->cmd[RIGHT]->type == T_BUILT)
	return (execute_(tree->cmd[RIGHT], pipe, sh));
      else
	return (f_exec(tree->cmd[RIGHT], pipe, sh, 1));
    }
  return (EXIT_SUCCESS);
}

int	exec_pipe(t_tree *tree, t_pipe **pipe, t_sh *sh, int dad)
{
  int	pid;
  int	ret;

  pid = fork();
  if (!pid)
    {
      if (!dad)
	new_group();
      exec_left(tree, pipe, sh, dad + 1);
      return (BYE);
    }
  else
    {
      if (tree->cmd[RIGHT] && tree->cmd[RIGHT]->type == T_BUILT)
	{
	  wait(NULL);
	  kill_red_read(pipe);
	  if (!dad)
	    ret = last_builtin(tree->cmd[RIGHT], &(sh->env), sh, *pipe);
	  kill_pipe(pipe);
	  return (ret);
	}
      ret = exec_right(tree, pipe, sh, dad);
      kill_pipe(pipe);
      return (ret);
    }
  return (RETURN_ERROR);
}
