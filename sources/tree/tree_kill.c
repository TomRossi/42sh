/*
** tree_kill.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Tue May 15 10:18:39 2012 tom rossi
** Last update Sat May 19 09:52:18 2012 tom rossi
*/

#include <stdio.h>
#include <tree.h>
#include <unistd.h>

void    kill_red_read(t_pipe **pipe)
{
  t_pipe        *tmp;

  tmp = *pipe;
  while (tmp && (tmp->type != T_RED || tmp->mode != M_READ))
    tmp = tmp->next;
  if (tmp)
    {
      tmp->mode = M_NONE;
      if (tmp->fd == IS_DOUBLE)
	{
	  close(tmp->p[0]);
	  close(tmp->p[1]);
	}
    }
}

void    kill_red_write(t_pipe **pipe)
{
  t_pipe        *tmp;

  tmp = *pipe;
  while (tmp && (tmp->type != T_RED || tmp->mode != M_WRITE))
    tmp = tmp->next;
  if (tmp)
    tmp->mode = M_NONE;
}

void    kill_pipe(t_pipe **pipe)
{
  t_pipe *tmp;

  tmp = *pipe;
  while (tmp && tmp->type != T_PIPE && tmp->mode != M_READ)
    tmp = tmp->next;
  if (!tmp)
    return;
  tmp->mode = M_NONE;
}
