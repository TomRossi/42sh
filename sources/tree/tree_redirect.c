/*
** tree_redirect.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Wed Apr 25 13:39:01 2012 tom rossi
** Last update Sat May 19 11:13:51 2012 tom rossi
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <token.h>
#include <str.h>
#include <tree.h>

t_pipe	*search_file(t_pipe *tmp)
{
  t_pipe	*file;

  file = tmp;
  while (file && !(file->type == T_RED && file->mode == M_READ))
    file = file->next;
  if (file)
    file->mode = M_VOID;
  if (file)
    return (file);
  file = tmp;
  while (file && file->mode != M_READ)
    file = file->next;
  return (file);
}

int	set_output(t_pipe *new, int type, char *path)
{
  if (!path || red_access(path, OUTPUT) == RETURN_ERROR)
    return (RETURN_ERROR);
  if (type == T_OUT_S)
    new->fd = open(path, O_WRONLY | O_CREAT
		   | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  else if (type == T_OUT_D)
    new->fd = open(path, O_WRONLY | O_CREAT
		   | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (new->fd <= 0)
    {
      printf("%s: Couldn't open the file.\n", path);
      return (RETURN_ERROR);
    }
  return (RETURN_SUCCESS);
}

int	set_input(t_pipe *new, int type, char *path)
{
  if (type == T_IN_D)
    {
      tcpgrp_reset();
      new->data = double_red(path);
      new->fd = IS_DOUBLE;
      if (!new->data)
	return (RETURN_ERROR);
      return (RETURN_SUCCESS);
    }
  if (red_access(path, INPUT) == RETURN_ERROR)
    return (RETURN_ERROR);
  if (type == T_IN_S)
    {
      new->fd = open(path, O_RDONLY);
      if (new->fd < 0)
	return (RETURN_ERROR);
    }
  return (RETURN_SUCCESS);
}

int	tree_redirect(t_pipe *new, int type, t_tree *tree)
{
  int	ret;

  if (!tree->cmd[RIGHT] || !tree->cmd[RIGHT]->av || !tree->cmd[RIGHT]->av[0])
    {
      printf("Error: redirection.\n");
      return (RETURN_ERROR);
    }
  if (type == T_IN_S || type == T_IN_D)
    ret = set_input(new, type, tree->cmd[RIGHT]->av[0]);
  else if (type == T_OUT_S || type == T_OUT_D)
    ret = set_output(new, type, tree->cmd[RIGHT]->av[0]);
  else
    {
      printf("Error: redirection.\n");
      ret = RETURN_ERROR;
    }
  return (ret);
}
