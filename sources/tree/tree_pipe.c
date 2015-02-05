/*
** tree_pipe.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Fri Apr 20 08:40:59 2012 tom rossi
** Last update Sat May 19 11:12:58 2012 tom rossi
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <token.h>
#include <str.h>
#include <tree.h>

void	pipe_write(t_pipe *p)
{
  int	fd;

  if (p->type == T_PIPE)
    fd = p->p[1];
  else
    fd = p->fd;
  if (p->type == T_PIPE)
    close(p->p[0]);
  dup2(fd, 1);
}

void	pipe_read(t_pipe *p)
{
  int	fd;

  if (p->type == T_PIPE)
    fd = p->p[0];
  else
    fd = p->fd;
  if (fd == IS_DOUBLE)
    {
      my_putfd(p->data, p->p[1]);
      close(p->p[1]);
      dup2(p->p[0], 0);
      close(p->p[0]);
      return;
    }
  close(p->p[1]);
  dup2(fd, 0);
}

void	pipe_skip(t_pipe *r, t_pipe *w)
{
  int	fd;
  int	fdr;

  close(w->p[0]);
  if (w->type == T_PIPE)
    fd = w->p[1];
  else
    fd = w->fd;
  if (r->type == T_PIPE)
    fdr = r->p[0];
  else
    fdr = r->fd;
  if (fdr != IS_DOUBLE)
    {
      close(r->p[1]);
      dup2(fd, 1);
      dup2(fdr, 0);
      close(fd);
      return;
    }
  my_putfd(r->data, r->p[1]);
  close(r->p[1]);
  dup2(r->p[0], 0);
  dup2(fd, 1);
  close(r->p[0]);
  close(fd);
}

void	dup_pipe(t_pipe **_pipe, int type)
{
  t_pipe        *tmp_read;
  t_pipe        *tmp_write;

  tmp_write = *_pipe;
  tmp_read = search_file(*_pipe);
  while (tmp_write && tmp_write->mode != M_WRITE)
    tmp_write = tmp_write->next;
  if (tmp_read && !tmp_write && type != T_BUILT)
    pipe_read(tmp_read);
  else if (tmp_write && !tmp_read)
    pipe_write(tmp_write);
  else if (tmp_write && tmp_read)
    pipe_skip(tmp_read, tmp_write);
}

int	tree_pipe(t_pipe **_pipe, int type, t_tree *tree)
{
  t_pipe	*new;
  int		ret;

  ret = RETURN_SUCCESS;
  if (!(new = malloc(sizeof(*new))))
    return (RETURN_ERROR);
  if (type == T_PIPE)
    new->type = type;
  else
    new->type = T_RED;
  new->fd = NONE;
  new->prev = NULL;
  pipe(new->p);
  new->mode = M_WRITE;
  if (type == T_IN_S || type == T_IN_D)
    new->mode = M_READ;
  new->next = *_pipe;
  if (new->type == T_RED)
    ret = tree_redirect(new, type, tree);
  if (ret == RETURN_ERROR)
    return (RETURN_ERROR);
  if (*_pipe)
    (*_pipe)->prev = new;
  *_pipe = new;
  return (ret);
}
