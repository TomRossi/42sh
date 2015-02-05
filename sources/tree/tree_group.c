/*
** tree_group.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Wed May 16 13:34:47 2012 tom rossi
** Last update Sat May 19 14:02:09 2012 tom rossi
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <token.h>

int	new_group()
{
  if (setpgrp() < 0)
    return (RETURN_ERROR);
  else if (tcsetpgrp(0, getpgrp()) < 0)
    return (RETURN_ERROR);
  else if (tcsetpgrp(1, getpgrp()) < 0)
    return (RETURN_ERROR);
  else
    return (RETURN_SUCCESS);
  return (RETURN_ERROR);
}
