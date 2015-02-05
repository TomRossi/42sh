/*
** tree_env.c for sh in /home/rossi_t//random/projets/42sh
** 
** Made by tom rossi
** Login   <rossi_t@epitech.net>
** 
** Started on  Fri May 18 15:45:29 2012 tom rossi
** Last update Fri May 18 15:50:57 2012 tom rossi
*/

#include <stdlib.h>
#include <tree.h>
#include <str.h>
#include <builtin.h>

void    set_env_return(t_sh *sh, int ret)
{
  char  *tab[4];

  tab[0] = "setenv";
  tab[1] = "?";
  tab[2] = my_getstr(ret);
  tab[3] = NULL;
  set_env(&(sh->env), tab, 1);
}
